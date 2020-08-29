--- src/jtag/drivers/bitbang.h.orig	2020-08-29 10:55:23 UTC
+++ src/jtag/drivers/bitbang.h
@@ -35,7 +35,7 @@ struct bitbang_interface {
 	void (*swdio_drive)(bool on);
 };
 
-const struct swd_driver bitbang_swd;
+extern const struct swd_driver bitbang_swd;
 
 extern bool swd_mode;
 
