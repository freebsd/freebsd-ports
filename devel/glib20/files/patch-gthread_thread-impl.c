--- gthread/gthread-impl.c.orig	Fri Feb 14 16:08:46 2003
+++ gthread/gthread-impl.c	Wed Jul 20 19:44:08 2005
@@ -37,9 +37,11 @@
 
 #include <glib.h>
 #include <gthreadinit.h>
+#include "gthreadprivate.h"
 
 #ifdef G_THREADS_ENABLED
 
+static GSystemThread zero_thread; /* This is initialized to all zero */
 static gboolean thread_system_already_initialized = FALSE;
 static gint g_thread_priority_map [G_THREAD_PRIORITY_URGENT + 1];
 
@@ -76,7 +78,7 @@
 struct _ErrorCheckInfo
 {
   gchar *location;
-  GThread *owner;
+  GSystemThread owner;
 };
 
 static GMutex *
@@ -94,7 +96,9 @@
 			      gchar *location)
 {
   ErrorCheckInfo *info;
-  GThread *self = g_thread_self ();
+  GSystemThread self;
+
+  g_thread_functions_for_glib_use.thread_self (&self);
 
   if (magic != G_MUTEX_DEBUG_MAGIC)
     location = "unknown";
@@ -116,14 +120,14 @@
     }
   
   info = G_MUTEX_DEBUG_INFO (mutex);
-  if (info->owner == self)
+  if (g_system_thread_equal (info->owner, self))
     g_error ("Trying to recursivly lock a mutex at '%s', "
 	     "previously locked at '%s'", 
 	     location, info->location);
 
   g_thread_functions_for_glib_use_default.mutex_lock (mutex);
 
-  info->owner = self;
+  g_system_thread_assign (info->owner, self);
   info->location = location;
 }
 
@@ -133,7 +137,9 @@
 				 gchar *location)
 {
   ErrorCheckInfo *info = G_MUTEX_DEBUG_INFO (mutex);
-  GThread *self = g_thread_self ();
+  GSystemThread self;
+
+  g_thread_functions_for_glib_use.thread_self (&self);
 
   if (magic != G_MUTEX_DEBUG_MAGIC)
     location = "unknown";
@@ -145,7 +151,7 @@
       return TRUE;
     }
 
-  if (info->owner == self)
+  if (g_system_thread_equal (info->owner, self))
     g_error ("Trying to recursivly lock a mutex at '%s', "
 	     "previously locked at '%s'", 
 	     location, info->location);
@@ -153,7 +159,7 @@
   if (!g_thread_functions_for_glib_use_default.mutex_trylock (mutex))
     return FALSE;
 
-  info->owner = self;
+  g_system_thread_assign (info->owner, self);
   info->location = location;
 
   return TRUE;
@@ -165,20 +171,22 @@
 				gchar *location)
 {
   ErrorCheckInfo *info = G_MUTEX_DEBUG_INFO (mutex);
-  GThread *self = g_thread_self ();
+  GSystemThread self;
+
+  g_thread_functions_for_glib_use.thread_self (&self);
 
   if (magic != G_MUTEX_DEBUG_MAGIC)
     location = "unknown";
 
-  if (!info || info->owner == NULL)
+  if (!info || g_system_thread_equal (info->owner, zero_thread))
     g_error ("Trying to unlock an unlocked mutex at '%s'", location);
 
-  if (info->owner != self)
+  if (!g_system_thread_equal (info->owner, self))
     g_warning ("Trying to unlock a mutex at '%s', "
 	       "previously locked by a different thread at '%s'",
 	       location, info->location);
 
-  info->owner = NULL;
+  g_system_thread_assign (info->owner, zero_thread);
   info->location = NULL;
 
   g_thread_functions_for_glib_use_default.mutex_unlock (mutex);
@@ -194,7 +202,7 @@
   if (magic != G_MUTEX_DEBUG_MAGIC)
     location = "unknown";
 
-  if (info && info->owner != NULL)
+  if (info && !g_system_thread_equal (info->owner, zero_thread))
     g_error ("Trying to free a locked mutex at '%s', "
 	     "which was previously locked at '%s'", 
 	     location, info->location);
@@ -211,25 +219,27 @@
 {
   
   ErrorCheckInfo *info = G_MUTEX_DEBUG_INFO (mutex);
-  GThread *self = g_thread_self ();
+  GSystemThread self;
+
+  g_thread_functions_for_glib_use.thread_self (&self);
 
   if (magic != G_MUTEX_DEBUG_MAGIC)
     location = "unknown";
 
-  if (!info || info->owner == NULL)
+  if (!info || g_system_thread_equal (info->owner, zero_thread))
     g_error ("Trying to use an unlocked mutex in g_cond_wait() at '%s'",
 	     location);
 
-  if (info->owner != self)
+  if (!g_system_thread_equal (info->owner, self))
     g_error ("Trying to use a mutex locked by another thread in "
 	     "g_cond_wait() at '%s'", location);
 
-  info->owner = NULL;
+  g_system_thread_assign (info->owner, zero_thread);
   location = info->location;
 
   g_thread_functions_for_glib_use_default.cond_wait (cond, mutex);
 
-  info->owner = self;
+  g_system_thread_assign (info->owner, self);
   info->location = location;
 }
     
@@ -242,28 +252,30 @@
 				   gchar *location)
 {
   ErrorCheckInfo *info = G_MUTEX_DEBUG_INFO (mutex);
-  GThread *self = g_thread_self ();
+  GSystemThread self;
   gboolean retval;
 
+  g_thread_functions_for_glib_use.thread_self (&self);
+
   if (magic != G_MUTEX_DEBUG_MAGIC)
     location = "unknown";
 
-  if (!info || info->owner == NULL)
+  if (!info || g_system_thread_equal (info->owner, zero_thread))
     g_error ("Trying to use an unlocked mutex in g_cond_timed_wait() at '%s'",
 	     location);
 
-  if (info->owner != self)
+  if (!g_system_thread_equal (info->owner, self))
     g_error ("Trying to use a mutex locked by another thread in "
 	     "g_cond_timed_wait() at '%s'", location);
 
-  info->owner = NULL;
+  g_system_thread_assign (info->owner, zero_thread);
   location = info->location;
   
   retval = g_thread_functions_for_glib_use_default.cond_timed_wait (cond, 
 								    mutex, 
 								    end_time);
 
-  info->owner = self;
+  g_system_thread_assign (info->owner, self);
   info->location = location;
 
   return retval;
