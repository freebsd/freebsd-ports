--- utils/vcc/vcc.cpp.orig	2022-12-31 03:37:54 UTC
+++ utils/vcc/vcc.cpp
@@ -122,7 +122,7 @@ int main(int argc, char **argv)
 	}
 	catch (VException& e)
 	{
-		FatalError(e.What());
+		FatalError("%s", e.What());
 	}
 	return 0;
 }
@@ -171,7 +171,7 @@ static void DisplayUsage()
 {
 	//	Print usage.
 	printf("\n");
-	printf("VCC Version 1.%d. Copyright (c)2000-2001 by JL.          ("__DATE__" "__TIME__")\n", PROG_VERSION);
+	printf("VCC Version 1.%d. Copyright (c)2000-2001 by JL.          (" __DATE__ " " __TIME__ ")\n", PROG_VERSION);
 	printf("Usage: vcc [options] source[.c] [object[.dat]]\n");
 	printf("    -d<file>     Output debugging information into specified file\n");
 	printf("    -a<function> Output function's ASM statements into debug file\n");
