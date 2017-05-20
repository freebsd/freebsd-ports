# We don't have MAP_NORESERVE so use MAP_NOSYNC | MAP_NOCORE and
# hope for the best (this alloc is too big but it's only a test)
#
--- src/intel/tools/aubinator.c.orig	2017-04-01 15:33:37 UTC
+++ src/intel/tools/aubinator.c
@@ -1299,7 +1299,7 @@ int main(int argc, char *argv[])
    /* mmap a terabyte for our gtt space. */
    gtt_size = 1ull << 40;
    gtt = mmap(NULL, gtt_size, PROT_READ | PROT_WRITE,
-              MAP_PRIVATE | MAP_ANONYMOUS |  MAP_NORESERVE, -1, 0);
+              MAP_PRIVATE | MAP_ANONYMOUS | MAP_NOSYNC | MAP_NOCORE, -1, 0);
    if (gtt == MAP_FAILED) {
       fprintf(stderr, "failed to alloc gtt space: %s\n", strerror(errno));
       exit(EXIT_FAILURE);
