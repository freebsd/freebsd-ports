--- array.c.orig	2008-06-21 12:28:01.000000000 +0400
+++ array.c	2008-06-21 12:37:24.000000000 +0400
@@ -20,6 +20,7 @@
 static ID id_cmp;
 
 #define ARY_DEFAULT_SIZE 16
+#define	ARY_MAX_SIZE (LONG_MAX / sizeof(VALUE))
 
 void
 rb_mem_clear(mem, size)
@@ -120,7 +121,7 @@
     if (len < 0) {
 	rb_raise(rb_eArgError, "negative array size (or size too big)");
     }
-    if (len > 0 && len * sizeof(VALUE) <= len) {
+    if (len > ARY_MAX_SIZE) {
 	rb_raise(rb_eArgError, "array size too big");
     }
     if (len == 0) len++;
@@ -293,7 +294,7 @@
     if (len < 0) {
 	rb_raise(rb_eArgError, "negative array size");
     }
-    if (len > 0 && len * (long)sizeof(VALUE) <= len) {
+    if (len > ARY_MAX_SIZE) {
 	rb_raise(rb_eArgError, "array size too big");
     }
     if (len > RARRAY(ary)->aux.capa) {
@@ -359,6 +360,10 @@
 	}
     }
 
+    if (idx >= ARY_MAX_SIZE) {
+        rb_raise(rb_eIndexError, "index %ld too big", idx);
+    }
+
     rb_ary_modify(ary);
     if (idx >= RARRAY(ary)->aux.capa) {
 	long new_capa = RARRAY(ary)->aux.capa / 2;
@@ -366,6 +371,9 @@
 	if (new_capa < ARY_DEFAULT_SIZE) {
 	    new_capa = ARY_DEFAULT_SIZE;
 	}
+	if (new_capa >= ARY_MAX_SIZE - idx) {
+	    new_capa = (ARY_MAX_SIZE - idx) / 2;
+	}
 	new_capa += idx;
 	if (new_capa * (long)sizeof(VALUE) <= new_capa) {
 	    rb_raise(rb_eArgError, "index too big");
@@ -975,6 +983,9 @@
     rb_ary_modify(ary);
 
     if (beg >= RARRAY(ary)->len) {
+	if (beg > ARY_MAX_SIZE - rlen) {
+	    rb_raise(rb_eIndexError, "index %ld too big", beg);
+	}
 	len = beg + rlen;
 	if (len >= RARRAY(ary)->aux.capa) {
 	    REALLOC_N(RARRAY(ary)->ptr, VALUE, len);
@@ -2378,7 +2389,7 @@
     if (len < 0) {
 	rb_raise(rb_eArgError, "negative argument");
     }
-    if (LONG_MAX/len < RARRAY(ary)->len) {
+    if (ARY_MAX_SIZE/len < RARRAY(ary)->len) {
 	rb_raise(rb_eArgError, "argument too big");
     }
     len *= RARRAY(ary)->len;
