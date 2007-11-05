--- src/misc/memcpy.c.orig	2007-11-02 12:33:04.000000000 +0100
+++ src/misc/memcpy.c	2007-11-02 12:35:27.000000000 +0100
@@ -226,8 +226,8 @@
                                     "movq %%mm6, 48(%1)\n"
                                     "movq %%mm7, 56(%1)\n"
                                     :: "r" (from), "r" (to) : "memory");
-               ((const unsigned char *)from)+=64;
-               ((unsigned char *)to)+=64;
+               from = (const unsigned char *)from + 64;
+               to = (unsigned char *)to + 64;
           }
           __asm__ __volatile__ ("emms":::"memory");
      }
@@ -288,8 +288,8 @@
                                     "movntq %%mm6, 48(%1)\n"
                                     "movntq %%mm7, 56(%1)\n"
                                     :: "r" (from), "r" (to) : "memory");
-               ((const unsigned char *)from)+=64;
-               ((unsigned char *)to)+=64;
+               from = (const unsigned char *)from + 64;
+               to = (unsigned char *)to + 64;
           }
           /* since movntq is weakly-ordered, a "sfence"
           * is needed to become ordered again. */
@@ -346,8 +346,8 @@
                                          "movntps %%xmm2, 32(%1)\n"
                                          "movntps %%xmm3, 48(%1)\n"
                                          :: "r" (from), "r" (to) : "memory");
-                    ((const unsigned char *)from)+=64;
-                    ((unsigned char *)to)+=64;
+                    from = (const unsigned char *)from + 64;
+                    to = (unsigned char *)to + 64;
                }
           else
                /*
@@ -368,8 +368,8 @@
                                          "movntps %%xmm2, 32(%1)\n"
                                          "movntps %%xmm3, 48(%1)\n"
                                          :: "r" (from), "r" (to) : "memory");
-                    ((const unsigned char *)from)+=64;
-                    ((unsigned char *)to)+=64;
+                    from = (const unsigned char *)from + 64;
+                    to = (unsigned char *)to + 64;
                }
           /* since movntq is weakly-ordered, a "sfence"
            * is needed to become ordered again. */
