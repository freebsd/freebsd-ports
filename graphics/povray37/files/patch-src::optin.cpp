--- src/optin.cpp.orig	Sun Dec 28 23:43:15 2003
+++ src/optin.cpp	Sun Dec 28 23:43:52 2003
@@ -364,7 +364,7 @@
 
 static bool matches(char *v1, char *v2);
 
-POV_ISTREAM *Opts_Locate_File(char *filename, unsigned long stype, char *buffer, int err_flag, POVMSObjectPtr obj);
+POV_ISTREAM *Opts_Locate_File(char *filename, u_int32 stype, char *buffer, int err_flag, POVMSObjectPtr obj);
 
 
 /*****************************************************************************
