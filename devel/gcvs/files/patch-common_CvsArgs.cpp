--- common/CvsArgs.cpp.orig	2002-06-27 19:02:08 UTC
+++ common/CvsArgs.cpp
@@ -198,7 +198,7 @@ void CvsArgs::print(const char *indirect
 	{
 		CStr newarg;
 		newarg = argv[i];
-		bool hasLF = strchr(newarg, '\n') != 0L;
+		bool hasLF = strchr((const char*)newarg, '\n') != 0L;
 		size_t len = newarg.length();
 
 		if(len > MAX_PRINT_ARG)
@@ -207,7 +207,7 @@ void CvsArgs::print(const char *indirect
 		if(hasLF)
 			newarg = expandLF(newarg, buf);
 
-		bool hasSpace = strchr(newarg, ' ') != 0L;
+		bool hasSpace = strchr((const char*)newarg, ' ') != 0L;
 		if(hasSpace)
 			cvs_out("\"");
 		cvs_outstr(newarg, newarg.length());
