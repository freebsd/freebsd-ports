--- libinjection_sqli.c.orig	2017-05-21 20:44:26 UTC
+++ libinjection_sqli.c
@@ -1197,7 +1197,7 @@ static size_t parse_number(struct libinjection_sqli_st
  * without having to regenerated the SWIG (or other binding) in minor
  * releases.
  */
-const char* libinjection_version()
+const char* libinjection_version(void)
 {
     return LIBINJECTION_VERSION;
 }
