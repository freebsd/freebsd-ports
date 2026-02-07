Fix build with aarch64, armv6, and armv7

#--- mpdm_s.o ---
mpdm_s.c:1070:5: error: conflicting types for '__wcwidth'
int wcwidth(wchar_t);
    ^
/usr/include/wchar.h:211:21: note: expanded from macro 'wcwidth'
#define wcwidth(_c)     __wcwidth(_c)
                        ^
/usr/include/_ctype.h:159:1: note: previous definition is here
__wcwidth(__ct_rune_t _c)
^
1 error generated.
*** [mpdm_s.o] Error code 1

--- mpdm/mpdm_s.c.orig	2020-10-11 16:50:34 UTC
+++ mpdm/mpdm_s.c
@@ -758,8 +758,6 @@ int mpdm_gettext_domain(const mpdm_t dom, const mpdm_t
 
 #ifdef CONFOPT_WCWIDTH
 
-int wcwidth(wchar_t);
-
 int mpdm_wcwidth(wchar_t c)
 {
     return wcwidth(c);
