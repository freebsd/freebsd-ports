--- modules/gettext/seed-gettext.c.orig	2009-07-26 19:23:31.000000000 -0400
+++ modules/gettext/seed-gettext.c	2009-07-26 19:25:12.000000000 -0400
@@ -293,12 +293,24 @@ seed_module_init(SeedEngine *local_eng)
 	DEFINE_ENUM_MEMBER(ns_ref, LC_MONETARY);
 	DEFINE_ENUM_MEMBER(ns_ref, LC_MESSAGES);
 	DEFINE_ENUM_MEMBER(ns_ref, LC_ALL);
+#ifdef LC_PAPER
 	DEFINE_ENUM_MEMBER(ns_ref, LC_PAPER);
+#endif
+#ifdef LC_NAME
 	DEFINE_ENUM_MEMBER(ns_ref, LC_NAME);
+#endif
+#ifdef LC_ADDRESS
 	DEFINE_ENUM_MEMBER(ns_ref, LC_ADDRESS);
+#endif
+#ifdef LC_TELEPHONE
 	DEFINE_ENUM_MEMBER(ns_ref, LC_TELEPHONE);
+#endif
+#ifdef LC_MEASUREMENT
 	DEFINE_ENUM_MEMBER(ns_ref, LC_MEASUREMENT);
+#endif
+#ifdef LC_IDENTIFICATION
 	DEFINE_ENUM_MEMBER(ns_ref, LC_IDENTIFICATION);
+#endif
 	DEFINE_ENUM_MEMBER(ns_ref, LC_CTYPE);
 
 	return ns_ref;
