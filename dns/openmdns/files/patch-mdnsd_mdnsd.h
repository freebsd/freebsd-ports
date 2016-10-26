In file included from log.c:33:
In file included from mdnsd/log.h:24:
In file included from mdnsd/mdnsd.h:30:
/usr/local/include/imsg.h:31:2: error: type name requires a specifier or qualifier
        TAILQ_ENTRY(ibuf)        entry;
        ^
/usr/local/include/imsg.h:31:14: error: a parameter list without types is only allowed in a function
      definition
        TAILQ_ENTRY(ibuf)        entry;
                    ^
/usr/local/include/imsg.h:31:19: error: expected ';' at end of declaration list
        TAILQ_ENTRY(ibuf)        entry;
                         ^
[...]

--- mdnsd/mdnsd.h.orig	2015-05-29 14:18:11 UTC
+++ mdnsd/mdnsd.h
@@ -18,6 +18,7 @@
 #define	_MDNSD_H_
 
 #include <sys/param.h>
+#include <sys/queue.h>
 #include <sys/socket.h>
 #include <sys/tree.h>
 #include <sys/types.h>
