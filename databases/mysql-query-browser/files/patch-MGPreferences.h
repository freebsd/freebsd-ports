--- mysql-gui-common/source/linux/MGPreferences.h.orig	Sat Apr  8 21:21:45 2006
+++ mysql-gui-common/source/linux/MGPreferences.h	Sat Apr  8 21:22:58 2006
@@ -40,7 +40,7 @@
     virtual MYX_APPLICATION_OPTIONS *prepare_options()= 0;
 
     const char *find_value(MYX_OPTION_GROUP *group, const char *name);
-    std::list<const char *>MGOptions::find_values(MYX_OPTION_GROUP *group, const char *name);
+    std::list<const char *> find_values(MYX_OPTION_GROUP *group, const char *name);
 
     void add_group(MYX_APPLICATION_OPTIONS *options, const char *name,
                    const std::list<ValuePair> &values);
