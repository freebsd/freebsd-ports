--- plugins/org.eclipse.core.net/natives/unix/GetProxyGnome/objects.mk.orig	2009-02-15 19:17:00.008787963 -0500
+++ plugins/org.eclipse.core.net/natives/unix/GetProxyGnome/objects.mk	2009-02-15 19:17:13.588843249 -0500
@@ -4,4 +4,4 @@
 
 USER_OBJS :=
 
-LIBS := -lgconf-2 -lORBit-2 -lgthread-2.0 -lrt -lgobject-2.0 -lglib-2.0
+LIBS := -L${LOCALBASE}/lib -lgconf-2 -lORBit-2 -lgthread-2.0 -lgobject-2.0 -lglib-2.0
