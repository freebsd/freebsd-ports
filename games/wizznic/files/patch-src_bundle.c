--- src/bundle.c.orig	2016-02-16 19:47:58 UTC
+++ src/bundle.c
@@ -104,7 +104,7 @@ int dirScan( const char* dir,int type, list_t* list )
         sprintf(buf, "%s/%s",dir,pent->d_name);
         if(stat(buf, &st)==0)
         {
-          if( (st.st_mode&S_IFDIR)==S_IFDIR )
+          if( (st.st_mode&S_IFMT)==S_IFDIR )
           {
             if( type==TYPE_DIR)
             {
@@ -120,7 +120,7 @@ int dirScan( const char* dir,int type, list_t* list )
             {
               return(0);
             }
-          } else if( (st.st_mode&&S_IFREG))
+          } else if( (st.st_mode&S_IFMT)==S_IFREG)
           {
             if( type== TYPE_FILE )
             {
