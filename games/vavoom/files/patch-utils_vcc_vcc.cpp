--- utils/vcc/vcc.cpp.orig	2018-03-17 07:31:45.795910000 +0100
+++ utils/vcc/vcc.cpp	2018-03-17 07:37:38.864263000 +0100
@@ -122,7 +122,7 @@
 	}
 	catch (VException& e)
 	{
-		FatalError(e.What());
+		FatalError("%s", e.What());
 	}
 	return 0;
 }
@@ -171,7 +171,7 @@
 {
 	//	Print usage.
 	printf("\n");
-	printf("VCC Version 1.%d. Copyright (c)2000-2001 by JL.          ("__DATE__" "__TIME__")\n", PROG_VERSION);
+	printf("VCC Version 1.%d. Copyright (c)2000-2001 by JL.          (" __DATE__ " " __TIME__ ")\n", PROG_VERSION);
 	printf("Usage: vcc [options] source[.c] [object[.dat]]\n");
 	printf("    -d<file>     Output debugging information into specified file\n");
 	printf("    -a<function> Output function's ASM statements into debug file\n");
