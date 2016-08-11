--- src/ash/output.h.orig	2012-07-17 22:30:18 UTC
+++ src/ash/output.h
@@ -65,8 +65,10 @@ void outfmt(struct output *, const char 
     __attribute__((__format__(__printf__,2,3)));
 void out1fmt(const char *, ...)
     __attribute__((__format__(__printf__,1,2)));
+#if 0
 void dprintf(const char *, ...)
     __attribute__((__format__(__printf__,1,2)));
+#endif
 void fmtstr(char *, size_t, const char *, ...)
     __attribute__((__format__(__printf__,3,4)));
 void doformat(struct output *, const char *, va_list);
