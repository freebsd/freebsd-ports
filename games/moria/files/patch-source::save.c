$FreeBSD$

--- source/save.c.orig	Thu Aug  7 16:24:56 2003
+++ source/save.c	Thu Aug  7 16:26:16 2003
@@ -102,7 +102,7 @@
 #endif
 
 #if !defined(ATARIST_MWC)
-#ifdef MAC
+#if defined(MAC) || defined(__FreeBSD__)
 #include <time.h>
 #else
 long time();
@@ -331,7 +331,7 @@
     }
 
   /* save the current time in the savefile */
-#ifdef MAC
+#if defined(MAC) || defined(__FreeBSD__)
   l = time((time_t *)0);
 #else
   l = time((long *)0);
@@ -1029,7 +1029,7 @@
 	      || (version_min == 2 && patch_level >= 2))
 	    rd_long ((int32u *)&birth_date);
 	  else
-#ifdef MAC
+#if defined(MAC) || defined(__FreeBSD__)
 	    birth_date = time((time_t *)0);
 #else
 	    birth_date = time((long *)0);
@@ -1253,7 +1253,7 @@
 	      /* rotate store inventory, depending on how old the save file */
 	      /* is foreach day old (rounded up), call store_maint */
 	      /* calculate age in seconds */
-#ifdef MAC
+#if defined(MAC) || defined(__FreeBSD__)
 	      start_time = time((time_t *)0);
 #else
 	      start_time = time((long *)0);
