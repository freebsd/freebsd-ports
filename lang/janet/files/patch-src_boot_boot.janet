https://github.com/janet-lang/janet/issues/327

../src/core/os.c:492:9: warning: implicit declaration of function 'unsetenv' is invalid in C99 [-Wimplicit-function-declaration]
        UNSETENV(ks);
        ^
../src/core/os.c:485:21: note: expanded from macro 'UNSETENV'
#define UNSETENV(K) unsetenv(K)
                    ^
../src/core/os.c:494:9: warning: implicit declaration of function 'setenv' is invalid in C99 [-Wimplicit-function-declaration]
        SETENV(ks, vs);
        ^
../src/core/os.c:484:21: note: expanded from macro 'SETENV'
#define SETENV(K,V) setenv(K, V, 1)
                    ^
../src/core/os.c:539:9: error: use of undeclared identifier 'CLOCK_MONOTONIC'
    if (gettime(&tv)) janet_panic("could not get time");
        ^
../src/core/os.c:532:35: note: expanded from macro 'gettime'
#define gettime(TV) clock_gettime(CLOCK_MONOTONIC, (TV))
                                  ^
../src/core/os.c:973:14: warning: implicit declaration of function 'S_ISSOCK' is invalid in C99 [-Wimplicit-function-declaration]
    else if (S_ISSOCK(m)) str = "socket";
             ^
../src/core/os.c:974:14: warning: implicit declaration of function 'S_ISLNK' is invalid in C99 [-Wimplicit-function-declaration]
    else if (S_ISLNK(m)) str = "link";
             ^
../src/core/os.c:1087:15: warning: implicit declaration of function 'lstat' is invalid in C99 [-Wimplicit-function-declaration]
        res = lstat(path, &st);
              ^
../src/core/math.c:256:28: warning: implicitly declaring library function 'trunc' with type 'double (double)' [-Wimplicit-function-declaration]
JANET_DEFINE_MATHOP(trunc, trunc)
                           ^
../src/core/math.c:256:28: note: include the header <math.h> or explicitly provide a declaration for 'trunc'
../src/core/math.c:257:28: warning: implicitly declaring library function 'round' with type 'double (double)' [-Wimplicit-function-declaration]
JANET_DEFINE_MATHOP(round, round)
                           ^
../src/core/math.c:257:28: note: include the header <math.h> or explicitly provide a declaration for 'round'
../src/core/math.c:468:50: error: use of undeclared identifier 'INFINITY'
    janet_def(env, "math/inf", janet_wrap_number(INFINITY),
                                                 ^
../src/core/math.c:470:52: error: use of undeclared identifier 'INFINITY'
    janet_def(env, "math/-inf", janet_wrap_number(-INFINITY),
                                                   ^

--- src/boot/boot.janet.orig	2020-03-30 11:49:04 UTC
+++ src/boot/boot.janet
@@ -2585,7 +2585,6 @@
   (print "#define JANET_BUILD \"" janet/build "\"")
   (print ```#define JANET_AMALG```)
   (print ```#define _POSIX_C_SOURCE 200112L```)
-  (print ```#define _XOPEN_SOURCE 500```)
   (print ```#include "janet.h"```)
 
   (defn do-one-flie
