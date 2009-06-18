--- class.c.orig	2009-06-18 16:17:27.000000000 +0400
+++ class.c	2009-06-18 16:17:42.000000000 +0400
@@ -153,7 +153,7 @@
 		data.klass = obj;
 		break;
 	      default:
-		data.klass = 0;
+		data.klass = Qnil;
 		break;
 	    }
 
