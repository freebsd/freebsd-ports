psocket.c:123:15: warning: implicit declaration of function 'ntohl' is invalid in C99 [-Wimplicit-function-declaration]
    *valueP = ntohl(converter.value);
              ^
psocket.c:196:23: warning: implicit declaration of function 'htonl' is invalid in C99 [-Wimplicit-function-declaration]
    converter.value = htonl(value);
                      ^
psocket.c:295:34: warning: implicit declaration of function 'htons' is invalid in C99 [-Wimplicit-function-declaration]
            nameEntry.sin_port = htons(tempShort);
                                 ^
psocket.c:358:32: warning: implicit declaration of function 'htons' is invalid in C99 [-Wimplicit-function-declaration]
        nameEntry.sin_port   = htons(trialPortNum);
                               ^

--- converter/ppm/ppmtompeg/psocket.c.orig	2020-03-27 19:26:06 UTC
+++ converter/ppm/ppmtompeg/psocket.c
@@ -9,7 +9,6 @@
 
 ============================================================================*/
 
-#define _XOPEN_SOURCE 500 /* Make sure stdio.h contains pclose() */
 /* _ALL_SOURCE is needed on AIX to make the C library include the
    socket services (e.g. define struct sockaddr)
 
