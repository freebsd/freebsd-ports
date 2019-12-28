mpdm_f.c:1947:9: error: use of undeclared identifier 'environ'
        environ = (char **) calloc(sizeof(char *), mpdm_size(v) + 1);

--- mpdm/mpdm_f.c.orig	2019-11-27 07:37:22 UTC
+++ mpdm/mpdm_f.c
@@ -1944,6 +1944,7 @@ static int sysdep_popen(mpdm_t v, char *prg, int rw)
 
         /* build the environment for the subprocess */
         v = mpdm_join(mpdm_get_wcs(mpdm_root(), L"ENV"), MPDM_S(L"="));
+        extern char **environ;
         environ = (char **) calloc(sizeof(char *), mpdm_size(v) + 1);
 
         mpdm_ref(v);
