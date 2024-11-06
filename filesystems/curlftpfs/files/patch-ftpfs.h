--- ftpfs.h.orig	2008-04-25 10:32:30 UTC
+++ ftpfs.h
@@ -75,7 +75,7 @@ extern struct ftpfs ftpfs;
         do { if (level <= ftpfs.debug) {\
                int i = 0; \
                while (++i < level) fprintf(stderr, " "); \
-               fprintf(stderr, "%ld ", time(NULL));\
+               fprintf(stderr, "%lld ", time(NULL));\
                fprintf(stderr, __FILE__ ":%d ", __LINE__);\
                fprintf(stderr, args);\
              }\
