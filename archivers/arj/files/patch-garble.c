--- garble.c.orig Fri Apr 18 10:12:36 2003
+++ garble.c Mon Feb 16 18:48:22 2004
@@ -298,12 +298,13 @@
     else
     {
      /* Get pathname of executable */
-     #if defined(SKIP_GET_EXE_NAME)
+     #if defined(SKIP_GET_EXE_NAME) && TARGET!=UNIX
       split_name(exe_name, tmp_arjcrypt_name, NULL);
      #elif defined(PKGLIBDIR)
       /* if !defined(PKGLIBDIR), we'll let the dynamic loader perform the
          search */
       strcpy(tmp_arjcrypt_name, PKGLIBDIR);
+      strcat(tmp_arjcrypt_name, "/");
      #endif
      if(arjcrypt_name==NULL||arjcrypt_name[0]=='\0')
       msg_strcat(tmp_arjcrypt_name, M_ARJCRYPT_COM);
