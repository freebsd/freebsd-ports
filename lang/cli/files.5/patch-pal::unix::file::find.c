
$FreeBSD$

--- pal/unix/file/find.c	2002/07/28 21:36:17	1.1
+++ pal/unix/file/find.c	2002/07/28 22:11:44
@@ -59,6 +59,7 @@
     HANDLE hRet = INVALID_HANDLE_VALUE;
     DWORD  dwLastError = NO_ERROR;
     find_obj *find_data = NULL;
+    int rval;
 
     ENTRY("FindFirstFileA(lpFileName=%s, lpFindFileData=%p)\n",
           lpFileName?lpFileName:"NULL", lpFindFileData);
@@ -86,9 +87,10 @@
 
     find_data->self_addr = find_data;
     
-    if ( FILEDosGlobA(lpFileName, 0, NULL, &(find_data->glob)) != 0 )
+    if ( (rval = FILEDosGlobA(lpFileName, 0, NULL, &(find_data->glob))) != 0 &&
+	rval != GLOB_NOMATCH )
     {
-        if ( errno == GLOB_NOSPACE )
+        if ( rval == GLOB_NOSPACE )
         {
             ERROR("glob failed on pattern [%s]\n", lpFileName);
             dwLastError = ERROR_NOT_ENOUGH_MEMORY;
