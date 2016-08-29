--- regutil/regmacrospace.c.orig	2009-10-07 07:51:51 UTC
+++ regutil/regmacrospace.c
@@ -59,7 +59,7 @@ rxfunc(sysaddrexxmacro)
       flags = RXMACRO_SEARCH_AFTER;
    }
 
-   result->strlength = sprintf(result->strptr, "%d", RexxAddMacro(fn, file, flags));
+   result->strlength = sprintf(result->strptr, "%lu", RexxAddMacro(fn, file, flags));
 
    return 0;
 }
@@ -69,7 +69,7 @@ rxfunc(sysclearrexxmacrospace)
 {
    checkparam(0, 0);
 
-   result->strlength = sprintf(result->strptr, "%d", RexxClearMacroSpace());
+   result->strlength = sprintf(result->strptr, "%lu", RexxClearMacroSpace());
    return 0;
 }
 
@@ -81,7 +81,7 @@ rxfunc(sysdroprexxmacro)
 
    rxstrdup(fn, argv[0]);
 
-   result->strlength = sprintf(result->strptr, "%d", RexxDropMacro(fn));
+   result->strlength = sprintf(result->strptr, "%lu", RexxDropMacro(fn));
    return 0;
 } 
 
@@ -94,7 +94,7 @@ rxfunc(sysloadrexxmacrospace)
 
    rxstrdup(file, argv[0]);
 
-   result->strlength = sprintf(result->strptr, "%d", RexxLoadMacroSpace(0, NULL, file));
+   result->strlength = sprintf(result->strptr, "%lu", RexxLoadMacroSpace(0, NULL, file));
    return 0;
 } 
 
@@ -143,7 +143,7 @@ rxfunc(sysreorderrexxmacro)
    else
       flags = RXMACRO_SEARCH_BEFORE;
 
-   result->strlength = sprintf(result->strptr, "%d", RexxReorderMacro(fn, flags));
+   result->strlength = sprintf(result->strptr, "%lu", RexxReorderMacro(fn, flags));
 
    return 0;
 } 
@@ -157,7 +157,7 @@ rxfunc(syssaverexxmacrospace)
 
    rxstrdup(file, argv[0]);
 
-   result->strlength = sprintf(result->strptr, "%d", RexxSaveMacroSpace(0, NULL, file));
+   result->strlength = sprintf(result->strptr, "%lu", RexxSaveMacroSpace(0, NULL, file));
    return 0;
 } 
 
