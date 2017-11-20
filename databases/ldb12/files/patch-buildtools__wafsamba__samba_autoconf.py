--- buildtools/wafsamba/samba_autoconf.py.orig	2016-10-07 04:45:35 UTC
+++ buildtools/wafsamba/samba_autoconf.py
@@ -873,7 +873,7 @@ def SAMBA_CHECK_UNDEFINED_SYMBOL_FLAGS(c
         conf.env.undefined_ldflags = conf.ADD_LDFLAGS('-Wl,-no-undefined', testflags=True)
 
     if not sys.platform.startswith("openbsd") and conf.env.undefined_ignore_ldflags == []:
-        if conf.CHECK_LDFLAGS(['-undefined', 'dynamic_lookup']):
+        if conf.CHECK_LDFLAGS(['-undefined', 'dynamic_lookup'] + conf.env.WERROR_CFLAGS):
             conf.env.undefined_ignore_ldflags = ['-undefined', 'dynamic_lookup']
 
 @conf
