--- m4/sah_header_stdcxx.m4.orig	Mon Nov 17 18:33:14 2003
+++ m4/sah_header_stdcxx.m4	Tue Mar  1 10:37:29 2005
@@ -9,7 +9,7 @@
   save_inc="$ac_includes_default"
   ac_includes_default="$ac_includes_default 
 #define CONFIG_TEST
-#include \"$BOINCDIR/lib/std_fixes.h\" 
+#include <BOINC/std_fixes.h>
 "
   sah_stdcxx_headers="algorithm bitset cassert cctype cerrno cfloat climits clocale cmath complex csetjmp csignal cstdarg cstddef cstdio cstdlib cstring ctime deque fstream functional iomanip ios iosfwd iostream istream iterator limits list locale map memory numeric ostream queue set sstream stack stdexcept streambuf string utility valarray vector"
   AC_LANG_PUSH(C++) 
