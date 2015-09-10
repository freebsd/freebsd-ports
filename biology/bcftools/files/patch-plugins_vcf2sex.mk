--- plugins/vcf2sex.mk.orig	2015-02-02 15:40:17 UTC
+++ plugins/vcf2sex.mk
@@ -1,2 +1,2 @@
-plugins/vcf2sex.so: plugins/vcf2sex.c version.h version.c ploidy.h ploidy.c $(HTSDIR)/libhts.so
-	$(CC) $(CFLAGS) $(INCLUDES) -fPIC -shared -o $@ ploidy.c version.c $< -L$(HTSDIR) -lhts
+plugins/vcf2sex.so: plugins/vcf2sex.c version.h version.c ploidy.h ploidy.c
+	$(CC) $(CFLAGS) $(LDFLAGS) $(INCLUDES) -fPIC -shared -o $@ ploidy.c version.c $< -lhts
