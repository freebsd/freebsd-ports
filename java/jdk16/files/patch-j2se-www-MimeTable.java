$FreeBSD$

--- ../../j2se/src/share/classes/sun/net/www/MimeTable.java.orig	Sun Jul 29 23:03:30 2007
+++ ../../j2se/src/share/classes/sun/net/www/MimeTable.java	Sun Jul 29 23:03:30 2007
@@ -40,9 +40,9 @@
 		    System.getProperty("user.home") + "/.mailcap",
 		    "/etc/mailcap",
 		    "/usr/etc/mailcap",
-		    "/usr/local/etc/mailcap",
+		    "%%LOCALBASE%%/etc/mailcap",
 		    System.getProperty("hotjava.home",
-				       "/usr/local/hotjava") + "/lib/mailcap",
+				       "%%LOCALBASE%%/hotjava") + "/lib/mailcap",
 		};
 		return null;
 	    }
