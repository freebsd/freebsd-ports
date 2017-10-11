--- tuntap.c.orig	2017-03-26 19:44:49 UTC
+++ tuntap.c
@@ -241,6 +241,25 @@ int             TUNTAP_CreateInterface( 
         strcpy( pszNetDevName, ifr.ifr_name );
     }
 #if !defined( OPTION_W32_CTCI )
+    else if ( strncasecmp( utsbuf.sysname, "FreeBSD",  7 ) == 0 )
+    {
+        struct stat sb;
+
+        if ( ( iFlags & IFF_TAP ) == IFF_TAP )
+        {
+            logmsg( _("HHCTU011E TAP device not yet supported\n") );
+            return -1;
+        }
+
+        if ( fstat(fd, &sb) == 0 )
+                devname_r(sb.st_rdev, S_IFCHR, pszNetDevName, IFNAMSIZ);
+        else
+        {
+            logmsg( _("HHCTU010E Error getting TUN/TAP device name: %s\n"),
+                    strerror( errno ) );
+            return -1;
+        }
+    }
     else
     {
         // Other OS: Simply use basename of the device
