--- src/CommonUtility/utils/PathUtils.cpp.orig	2024-09-12 07:10:38 UTC
+++ src/CommonUtility/utils/PathUtils.cpp
@@ -49,7 +49,8 @@ BOOL GetTempFileName(ESString DirName, ESString Prefix
 BOOL GetTempFileName(ESString DirName, ESString Prefix, LPTSTR TempFile)
 {
  size_t path_len = DirName.length() + Prefix.length() + strlen("XXXXXX");
- char *buf = (char *)malloc(path_len + 1);
+ // +2 for path separator added in ES_AddBackYen
+ char *buf = (char *)malloc(path_len + 2);
  buf[path_len] = 0;
  ES_CMN_FUNCS::PATH::ES_AddBackYen(DirName);
    strcpy(buf, DirName.c_str());
@@ -61,7 +62,7 @@ BOOL GetTempFileName(ESString DirName, ESString Prefix
      return FALSE;
  }
   FILE* fp = fdopen(fd, "w");
- memcpy(TempFile, buf, path_len+1);
+ memcpy(TempFile, buf, path_len+2);
   fclose(fp);
  free(buf);
   return TRUE;
@@ -606,7 +607,6 @@ namespace ES_CMN_FUNCS
       else
       {
        bResult = TRUE;
-       break;
       }
      }
 #endif
