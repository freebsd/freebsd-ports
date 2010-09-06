--- src/init.c	2010-05-08 19:56:15 +0000
+++ src/init.c	2010-07-28 19:22:22 +0000
@@ -252,6 +252,7 @@
   { "timeout",          NULL,                   cmd_spec_timeout },
   { "timestamping",     &opt.timestamping,      cmd_boolean },
   { "tries",            &opt.ntry,              cmd_number_inf },
+  { "trustservernames", &opt.trustservernames,  cmd_boolean },
   { "useproxy",         &opt.use_proxy,         cmd_boolean },
   { "user",             &opt.user,              cmd_string },
   { "useragent",        NULL,                   cmd_spec_useragent },

=== modified file 'src/main.c'
