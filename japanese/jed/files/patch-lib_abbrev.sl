--- lib/abbrev.sl	2000/10/01 17:41:08	1.1
+++ lib/abbrev.sl	2000/10/01 17:41:46
@@ -32,16 +32,16 @@
 define set_abbrev_mode (val)
 {
    getbuf_info ();
-   if (val) () | 0x800; else () & ~(0x800);
+   if (val) () | 0x1000; else () & ~(0x1000);
    setbuf_info(());
 }
 
 define abbrev_mode ()
 {
-   variable flags = getbuf_info() xor 0x800;
+   variable flags = getbuf_info() xor 0x1000;
    variable msg = "Abbrev mode OFF";
    setbuf_info(flags);
-   if (flags & 0x800) msg = "Abbrev mode ON";
+   if (flags & 0x1000) msg = "Abbrev mode ON";
    message (msg);
 }
 
