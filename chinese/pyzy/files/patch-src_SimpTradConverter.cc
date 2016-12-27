--- src/SimpTradConverter.cc.orig	2012-12-17 04:00:47 UTC
+++ src/SimpTradConverter.cc
@@ -40,7 +40,6 @@ namespace PyZy {
 #ifdef HAVE_OPENCC
 
 class opencc {
-    static const int BUFFER_SIZE = 64;
 public:
     opencc (void)
     {
@@ -55,29 +54,12 @@ public:
 
     void convert (const char *in, String &out)
     {
-        long n_char;
-        unichar *in_ucs4 = g_utf8_to_ucs4_fast (in, -1, &n_char);
-
-        ucs4_t *pinbuf = (ucs4_t *)in_ucs4;
-        size_t inbuf_left = n_char;
-        while (inbuf_left != 0) {
-            ucs4_t *poutbuf = (ucs4_t *)m_buffer;
-            size_t outbuf_left = BUFFER_SIZE;
-            size_t retval = opencc_convert(m_od, &pinbuf, &inbuf_left, &poutbuf, &outbuf_left);
-            if (retval == (size_t) -1) {
-                /* append left chars in pinbuf */
-                g_warning ("opencc_convert return failed");
-                out << (unichar *) pinbuf;
-                break;
-            }
-            *poutbuf = L'\0';
-            out << m_buffer;
-        }
-        g_free (in_ucs4);
+        char *converted = opencc_convert_utf8(m_od, in, -1);
+        out = converted;
+        opencc_convert_utf8_free(converted);
     }
 private:
     opencc_t m_od;
-    unichar m_buffer[BUFFER_SIZE + 1];
 };
 
 void
