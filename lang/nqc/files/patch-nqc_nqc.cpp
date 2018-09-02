nqc/nqc.cpp:1088:41: error: no matching literal operator for call to 'operator""__DATE__' with arguments of types 'const char *' and 'unsigned int', and no matching literal operator template
        fprintf(STDERR,"nqc version %s (built "__DATE__", " __TIME__")\n",

Remove embedded build date and time completely as it would also
prevent the build from being reproducible.

--- nqc/nqc.cpp.orig	2018-09-02 10:44:16 UTC
+++ nqc/nqc.cpp
@@ -1085,8 +1085,7 @@ void PrintError(RCX_Result error, const char *filename
 
 void PrintVersion()
 {
-	fprintf(STDERR,"nqc version %s (built "__DATE__", " __TIME__")\n",
-		VERSION_STRING);
+	fprintf(STDERR,"nqc version %s\n", VERSION_STRING);
 	fprintf(STDERR,"     Copyright (C) 2005 John Hansen.  All Rights Reserved.\n");
 }
 
