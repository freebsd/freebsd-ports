--- server/token.c.orig	2022-12-18 11:53:01.498015000 +0300
+++ server/token.c	2022-12-18 11:53:14.540515000 +0300
@@ -212,10 +212,10 @@ void init_user_sid(void)
     size_t n;
     FILE *f;
 
-    f = fopen( "/etc/machine-id", "r" );
+    f = fopen( "/var/lib/dbus/machine-id", "r" );
     if (!f)
     {
-        fprintf( stderr, "Failed to open /etc/machine-id, error %s.\n", strerror( errno ));
+        fprintf( stderr, "Failed to open /var/lib/dbus/machine-id, error %s.\n", strerror( errno ));
         return;
     }
 
@@ -224,7 +224,7 @@ void init_user_sid(void)
 
     if (n != 16)
     {
-        fprintf( stderr, "Failed to read /etc/machine-id, error %s.\n", strerror( errno ));
+        fprintf( stderr, "Failed to read /var/lib/dbus/machine-id, error %s.\n", strerror( errno ));
         return;
     }
     machine_id[n] = 0;
