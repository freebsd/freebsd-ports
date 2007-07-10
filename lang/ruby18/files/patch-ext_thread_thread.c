--- ext/thread/thread.c.orig	Sat Mar  3 13:08:06 2007
+++ ext/thread/thread.c	Tue Jul 10 03:08:38 2007
@@ -12,6 +12,7 @@
 #include <ruby.h>
 #include <intern.h>
 #include <rubysig.h>
+#include <node.h>
 
 static VALUE rb_cMutex;
 static VALUE rb_cConditionVariable;
@@ -163,13 +164,18 @@
 remove_one(List *list, VALUE value)
 {
     Entry **ref;
+    Entry *prev;
     Entry *entry;
 
-    for (ref = &list->entries, entry = list->entries;
+    for (ref = &list->entries, prev = NULL, entry = list->entries;
               entry != NULL;
-              ref = &entry->next, entry = entry->next) {
+              ref = &entry->next, prev = entry, entry = entry->next) {
         if (entry->value == value) {
             *ref = entry->next;
+            list->size--;
+            if (!entry->next) {
+                list->last_entry = prev;
+            }
             recycle_entries(list, entry, entry);
             break;
         }
@@ -202,15 +208,16 @@
 static VALUE
 wake_thread(VALUE thread)
 {
-    return rb_rescue2(rb_thread_wakeup, thread,
-      NULL, Qundef, rb_eThreadError, 0);
+    return rb_thread_wakeup_alive(thread);
 }
 
 static VALUE
 run_thread(VALUE thread)
 {
-    return rb_rescue2(rb_thread_run, thread,
-      NULL, Qundef, rb_eThreadError, 0);
+    thread = wake_thread(thread);
+    if (RTEST(thread) && !rb_thread_critical)
+	rb_thread_schedule();
+    return thread;
 }
 
 static VALUE
@@ -220,7 +227,9 @@
 
     waking = Qnil;
     while (list->entries && !RTEST(waking)) {
-        waking = wake_thread(shift_list(list));
+	waking = shift_list(list);
+	if (waking == Qundef) break;
+	waking = wake_thread(waking);
     }
 
     return waking;
@@ -251,7 +260,7 @@
     return Qnil;
 }
 
-static void
+static VALUE
 wait_list(List *list)
 {
     rb_ensure(wait_list_inner, (VALUE)list, wait_list_cleanup, (VALUE)list);
@@ -261,10 +270,17 @@
 assert_no_survivors(List *waiting, const char *label, void *addr)
 {
     Entry *entry;
+    VALUE ths = 0;
+
     for (entry = waiting->entries; entry; entry = entry->next) {
-        if (RTEST(wake_thread(entry->value))) {
-            rb_bug("%s %p freed with live thread(s) waiting", label, addr);
-        }
+	if (RTEST(wake_thread(entry->value))) {
+	    if (!ths) ths = rb_ary_new();
+	    rb_ary_push(ths, entry->value);
+	}
+    }
+    if (ths) {
+	rb_bug("%s %p freed with live thread(s) %s waiting",
+	       label, addr, RSTRING_PTR(rb_inspect(ths)));
     }
 }
 
@@ -298,6 +314,8 @@
     List waiting;
 } Mutex;
 
+#define MUTEX_LOCKED_P(mutex) (RTEST((mutex)->owner) && rb_thread_alive_p((mutex)->owner))
+
 static void
 mark_mutex(Mutex *mutex)
 {
@@ -356,7 +374,7 @@
 {
     Mutex *mutex;
     Data_Get_Struct(self, Mutex, mutex);
-    return RTEST(mutex->owner) ? Qtrue : Qfalse;
+    return MUTEX_LOCKED_P(mutex) ? Qtrue : Qfalse;
 }
 
 /*
@@ -375,7 +393,7 @@
 
     Data_Get_Struct(self, Mutex, mutex);
 
-    if (RTEST(mutex->owner))
+    if (MUTEX_LOCKED_P(mutex))
         return Qfalse;
 
     mutex->owner = rb_thread_current();
@@ -390,7 +408,7 @@
  *
  */
 
-static void
+static VALUE
 lock_mutex(Mutex *mutex)
 {
     VALUE current;
@@ -398,13 +416,23 @@
 
     rb_thread_critical = 1;
 
-    while (RTEST(mutex->owner)) {
-        wait_list(&mutex->waiting);
-        rb_thread_critical = 1;
+    if (!MUTEX_LOCKED_P(mutex)) {
+	mutex->owner = current;
+    }
+    else {
+	push_list(&mutex->waiting, current);
+	do {
+	    rb_thread_stop();
+	    rb_thread_critical = 1;
+	    if (!MUTEX_LOCKED_P(mutex)) {
+		mutex->owner = current;
+		break;
+	    }
+	} while (mutex->owner != current);
     }
-    mutex->owner = current; 
 
     rb_thread_critical = 0;
+    return Qnil;
 }
 
 static VALUE
@@ -416,6 +444,22 @@
     return self;
 }
 
+static VALUE
+relock_mutex(Mutex *mutex)
+{
+    VALUE current = rb_thread_current();
+
+    switch (rb_thread_status(current)) {
+      case THREAD_RUNNABLE:
+      case THREAD_STOPPED:
+	lock_mutex(mutex);
+	break;
+      default:
+	break;
+    }
+    return Qundef;
+}
+
 /*
  * Document-method: unlock
  *
@@ -428,11 +472,12 @@
 {
     VALUE waking;
 
-    if (!RTEST(mutex->owner)) {
-        return Qundef;
+    if (mutex->owner != rb_thread_current()) {
+	rb_raise(rb_eThreadError, "not owner");
     }
-    mutex->owner = Qnil;
+
     waking = wake_one(&mutex->waiting);
+    mutex->owner = waking;
 
     return waking;
 }
@@ -451,14 +496,11 @@
 
     rb_thread_critical = 1;
     waking = rb_ensure(unlock_mutex_inner, (VALUE)mutex, set_critical, 0);
-
-    if (waking == Qundef) {
+    if (!RTEST(waking)) {
         return Qfalse;
     }
 
-    if (RTEST(waking)) {
-        run_thread(waking);
-    }
+    run_thread(waking);
 
     return Qtrue;
 }
@@ -504,13 +546,11 @@
     rb_thread_critical = 1;
     waking = rb_ensure(rb_mutex_exclusive_unlock_inner, (VALUE)mutex, set_critical, 0);
 
-    if (waking == Qundef) {
+    if (waking == Qundef || !RTEST(waking)) {
         return Qnil;
     }
 
-    if (RTEST(waking)) {
-        run_thread(waking);
-    }
+    run_thread(waking);
 
     return self;
 }
@@ -622,19 +662,18 @@
 static void
 wait_condvar(ConditionVariable *condvar, Mutex *mutex)
 {
+    VALUE waking;
+
     rb_thread_critical = 1;
-    if (!RTEST(mutex->owner)) {
+    if (rb_thread_current() != mutex->owner) {
         rb_thread_critical = 0;
-        return;
+        rb_raise(rb_eThreadError, "not owner of the synchronization mutex");
     }
-    if (mutex->owner != rb_thread_current()) {
-        rb_thread_critical = 0;
-        rb_raise(rb_eThreadError, "Not owner");
+    waking = unlock_mutex_inner(mutex);
+    if (RTEST(waking)) {
+	wake_thread(waking);
     }
-    mutex->owner = Qnil;
-    wait_list(&condvar->waiting);
-
-    lock_mutex(mutex);
+    rb_ensure(wait_list, (VALUE)&condvar->waiting, relock_mutex, (VALUE)mutex);
 }
 
 static VALUE
@@ -830,10 +869,10 @@
 
     array = rb_marshal_load(data);
     if (TYPE(array) != T_ARRAY) {
-        rb_raise(rb_eRuntimeError, "expected Array of queue data");
+	rb_raise(rb_eTypeError, "expected Array of queue data");
     }
     if (RARRAY(array)->len < 1) {
-        rb_raise(rb_eRuntimeError, "missing capacity value");
+	rb_raise(rb_eArgError, "missing capacity value");
     }
     queue->capacity = NUM2ULONG(rb_ary_shift(array));
     push_multiple_list(&queue->values, RARRAY(array)->ptr, (unsigned)RARRAY(array)->len);
