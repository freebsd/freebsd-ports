$FreeBSD$

--- ../../j2se/src/share/classes/sun/net/www/protocol/doc/Handler.java.orig	Sun Jul 29 23:03:30 2007
+++ ../../j2se/src/share/classes/sun/net/www/protocol/doc/Handler.java	Sun Jul 29 23:03:30 2007
@@ -40,7 +40,7 @@
 	installDirectory = (String)java.security.AccessController.doPrivileged(
                 new sun.security.action.GetPropertyAction("hotjava.home"));
 	if (installDirectory == null) {
-	    installDirectory = "/usr/local/hotjava";
+	    installDirectory = "%%LOCALBASE%%/hotjava";
 	}
     }
     /*
