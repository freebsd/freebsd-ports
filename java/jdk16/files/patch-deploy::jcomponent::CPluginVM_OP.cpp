$FreeBSD$

--- ../../deploy/src/plugin/share/jcomponent/CPluginVM_OP.cpp.orig	Tue Oct 19 15:04:42 2004
+++ ../../deploy/src/plugin/share/jcomponent/CPluginVM_OP.cpp	Thu Jul  6 17:09:36 2006
@@ -305,7 +305,11 @@
     char * jre = m_ltstate->java_dir;
     
     // ARCH is passed in on the compile line
+#if defined(_ALLBSD_SOURCE) && defined(__amd64__)
+    sprintf(our_ld_paths,"%s/lib/%s/server:%s/lib/%s",jre,ARCH,jre,ARCH);
+#else
     sprintf(our_ld_paths,"%s/lib/%s/client:%s/lib/%s",jre,ARCH,jre,ARCH);
+#endif
 
     char * new_ld_lib_path;
 
