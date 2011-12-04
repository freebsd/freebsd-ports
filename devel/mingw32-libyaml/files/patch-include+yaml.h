--- include/yaml.h.orig	2011-05-31 10:58:42.000000000 +0900
+++ include/yaml.h	2011-12-05 02:54:28.221135420 +0900
@@ -26,6 +26,8 @@
 
 /** The public API declaration. */
 
+#define YAML_DECLARE_STATIC
+
 #ifdef _WIN32
 #   if defined(YAML_DECLARE_STATIC)
 #       define  YAML_DECLARE(type)  type
