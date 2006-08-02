--- src/file.c.orig	Sat Jul 29 00:55:36 2006
+++ src/file.c	Sat Jul 29 00:57:09 2006
@@ -1165,6 +1165,7 @@
 	    {
 	      menu = GetLibraryMenuMemory (&PCB->NetlistLib);
 	      menu->Name = MyStrdup (temp, "ReadNetlist()");
+	      menu->flag = 1;
 	      kind++;
 	    }
 	  else
