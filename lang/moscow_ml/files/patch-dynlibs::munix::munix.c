--- dynlibs/munix/munix.c.orig	Fri Jan 21 11:07:13 2000
+++ dynlibs/munix/munix.c	Fri Apr 12 00:27:33 2002
@@ -59,8 +59,9 @@
     failwith("EINVAL"); break;
   case EISDIR:
     failwith("EISDIR"); break;
-  case ELIBBAD:
+/*  case ELIBBAD:
     failwith("ELIBBAD"); break;
+ */
   case ECHILD:
     failwith("ECHILD"); break;
   case EINTR:
