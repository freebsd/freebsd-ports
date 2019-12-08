--- icu/makefile.mk.orig	2019-09-17 22:55:16 UTC
+++ icu/makefile.mk
@@ -86,6 +86,11 @@ LDFLAGSADD += -Wl,--hash-style=both
 LDFLAGSADD += -Wl,-Bsymbolic-functions -Wl,--dynamic-list-cpp-new -Wl,--dynamic-list-cpp-typeinfo
 .ENDIF
 
+# FreeBSD with gcc from ports needs -Wl,-rpath= to find the matching libstdc++ 
+.IF "$(OS)"=="FREEBSD"
+LDFLAGSADD+=$(FBSD_GCC_RPATH)
+.ENDIF
+
 CONFIGURE_DIR=source
 
 CONFIGURE_ACTION+=sh -c 'CFLAGS="$(icu_CFLAGS)" CXXFLAGS="$(icu_CXXFLAGS)" LDFLAGS="$(icu_LDFLAGS) $(LDFLAGSADD)" ./configure --enable-layout --enable-static --enable-shared=yes $(DISABLE_64BIT)'
