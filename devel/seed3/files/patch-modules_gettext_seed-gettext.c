--- modules/gettext/seed-gettext.c.orig	2009-12-31 05:42:51.000000000 -0500
+++ modules/gettext/seed-gettext.c	2010-01-07 19:07:10.000000000 -0500
@@ -312,12 +313,24 @@ seed_module_init(SeedEngine *local_eng)
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
