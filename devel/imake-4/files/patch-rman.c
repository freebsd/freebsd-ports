--- ../extras/rman/rman.c.orig	Tue Jul 15 23:53:53 2003
+++ ../extras/rman/rman.c	Tue Jul 15 23:44:21 2003
@@ -4104,6 +4104,9 @@
 	     }
 	   }
 	   break;
+	 case 0:
+	   /* ignore */
+	   break;
 	 default:		/* unknown escaped character */
 	   sputchar(*p++);
 	 }
