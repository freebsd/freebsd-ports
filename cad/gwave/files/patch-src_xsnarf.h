--- src/xsnarf.h.orig	2008-03-02 16:15:31.000000000 -0500
+++ src/xsnarf.h	2008-03-02 16:15:35.000000000 -0500
@@ -83,22 +83,22 @@ XSCM_SNARF_DOCS(concept, name, 0, 0, 0, 
 
 #define XSCM_VCELL(c_name, scheme_name, docstring) \
 XSCM_SNARF_HERE(static SCM c_name) \
-XSCM_SNARF_INIT(c_name = scm_permanent_object (scm_intern0 (scheme_name)); SCM_SETCDR (c_name, SCM_BOOL_F)); \
+XSCM_SNARF_INIT(c_name = scm_permanent_object (scm_str2symbol (scheme_name)); SCM_SETCDR (c_name, SCM_BOOL_F)); \
 XSCM_SNARF_DOCS(vcell, scheme_name, 0, 0, 0, 0, docstring)
 
 #define XSCM_GLOBAL_VCELL(c_name, scheme_name, docstring) \
 XSCM_SNARF_HERE(SCM c_name) \
-XSCM_SNARF_INIT(c_name = scm_permanent_object (scm_intern0 (scheme_name)); SCM_SETCDR (c_name, SCM_BOOL_F)); \
+XSCM_SNARF_INIT(c_name = scm_permanent_object (scm_str2symbol (scheme_name)); SCM_SETCDR (c_name, SCM_BOOL_F)); \
 XSCM_SNARF_DOCS(vcell, scheme_name, 0, 0, 0, 0, docstring)
 
 #define XSCM_VCELL_INIT(c_name, scheme_name, init_val, docstring) \
 XSCM_SNARF_HERE(static SCM c_name) \
-XSCM_SNARF_INIT(c_name = scm_permanent_object (scm_intern0 (scheme_name)); SCM_SETCDR (c_name, init_val));\
+XSCM_SNARF_INIT(c_name = scm_permanent_object (scm_str2symbol (scheme_name)); SCM_SETCDR (c_name, init_val));\
 XSCM_SNARF_DOCS(vcell, scheme_name, 0, 0, 0, 0, docstring)
 
 #define XSCM_GLOBAL_VCELL_INIT(c_name, scheme_name, init_val, docstring) \
 XSCM_SNARF_HERE(SCM c_name) \
-XSCM_SNARF_INIT(c_name = scm_permanent_object (scm_intern0 (scheme_name)); SCM_SETCDR (c_name, init_val));\
+XSCM_SNARF_INIT(c_name = scm_permanent_object (scm_str2symbol (scheme_name)); SCM_SETCDR (c_name, init_val));\
 XSCM_SNARF_DOCS(vcell, scheme_name, 0, 0, 0, 0, docstring)
 
 #endif /* GUILE_EXT_H__ */
