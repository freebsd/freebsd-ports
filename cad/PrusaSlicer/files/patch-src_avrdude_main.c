--- src/avrdude/main.c.orig	2021-08-13 03:29:34 UTC
+++ src/avrdude/main.c
@@ -806,7 +806,7 @@ int avrdude_main(int argc, char * argv [])
   avrdude_message(MSG_NOTICE, "\n%s: Version %s, compiled on %s at %s\n"
                     "%sCopyright (c) 2000-2005 Brian Dean, http://www.bdmicro.com/\n"
                     "%sCopyright (c) 2007-2014 Joerg Wunsch\n\n",
-                    progname, version, __DATE__, __TIME__, progbuf, progbuf);
+                    progname, version, "REDACTED", "REDACTED", progbuf, progbuf);
   // avrdude_message(MSG_NOTICE, "%sSystem wide configuration file is \"%s\"\n",
   //           progbuf, sys_config);
 
