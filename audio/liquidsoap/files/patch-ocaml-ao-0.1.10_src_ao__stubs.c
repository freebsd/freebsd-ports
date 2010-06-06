
$FreeBSD$

--- ocaml-ao-0.1.10/src/ao_stubs.c.orig
+++ ocaml-ao-0.1.10/src/ao_stubs.c
@@ -138,6 +138,7 @@
                        value channels,
                        value byte_format)
 {
+  memset(format, 0, sizeof(*format));
   format->bits = Int_val(bits);
   format->rate = Int_val(rate);
   format->channels = Int_val(channels);
