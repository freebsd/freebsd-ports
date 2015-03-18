--- src/VBox/Frontends/VBoxManage/VBoxManageModifyVM.cpp.orig	2015-03-02 10:09:37.000000000 -0500
+++ src/VBox/Frontends/VBoxManage/VBoxManageModifyVM.cpp	2015-03-12 18:33:09.348465000 -0400
@@ -1732,7 +1732,7 @@
                 CHECK_ERROR(nic, COMGETTER(NATEngine)(engine.asOutParam()));
 
                 uint32_t aliasMode = 0;
-                if (!RTStrCmp(ValueUnion.psz, "default") == 0)
+                if (RTStrCmp(ValueUnion.psz, "default") != 0)
                 {
                     char *token = (char *)ValueUnion.psz;
                     while(token)
