Index: libcpp/internal.h
===================================================================
RCS file: /cvs/gcc/gcc/libcpp/internal.h,v
retrieving revision 1.7
diff -u -3 -p -r1.7 internal.h
--- internal.h	9 Sep 2004 19:16:55 -0000	1.7
+++ internal.h	30 Oct 2004 17:27:31 -0000
@@ -29,6 +29,7 @@ Foundation, 59 Temple Place - Suite 330,
 #if defined HAVE_ICONV_H && defined HAVE_ICONV
 #include <iconv.h>
 #else
+#undef HAVE_ICONV
 #define HAVE_ICONV 0
 typedef int iconv_t;  /* dummy */
 #endif
