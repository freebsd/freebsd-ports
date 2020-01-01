--- liblepton/src/scheme_os.c.orig	2019-10-03 20:45:55 UTC
+++ liblepton/src/scheme_os.c
@@ -153,6 +153,25 @@ SCM_DEFINE (user_config_dir, "%user-conf
   return scm_from_locale_string(eda_get_user_config_dir());
 }
 
+/*! \brief Get user cache directory.
+ * \par Function Description
+ * Returns the directory where per-user cache data should be
+ * stored
+ *
+ * \note Scheme API: Implements the %user-cache-dir procedure is the
+ * (geda core os) module.
+ *
+ * \return a string.
+ */
+SCM_DEFINE (user_cache_dir, "%user-cache-dir", 0, 0, 0, (),
+            "Return the directory for user cache data.")
+{
+  /* eda_get_user_cache_dir() returns a raw environment string, so assume
+   * it's in the current locale's encoding. */
+  return scm_from_locale_string (eda_get_user_cache_dir ());
+}
+
+
 /*!
  * \brief Create the (geda core os) Scheme module.
  * \par Function Description
@@ -166,8 +185,12 @@ init_module_geda_core_os (void *unused)
   #include "scheme_os.x"
 
   /* Add them to the module's public definitions. */
-  scm_c_export (s_platform, s_sys_data_dirs, s_sys_config_dirs,
-                s_user_data_dir, s_user_config_dir,
+  scm_c_export (s_platform,
+                s_sys_config_dirs,
+                s_sys_data_dirs,
+                s_user_cache_dir,
+                s_user_config_dir,
+                s_user_data_dir,
                 NULL);
 }
 
