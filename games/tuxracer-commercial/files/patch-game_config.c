--- src/game_config.c.orig	Sun Aug 17 17:59:46 2003
+++ src/game_config.c	Sun Aug 17 18:02:15 2003
@@ -114,26 +114,26 @@
  */
 
 #define INIT_PARAM( nam, val, typename, commnt ) \
-   Params. ## nam ## .loaded = False; \
-   Params. ## nam ## .name = #nam; \
-   Params. ## nam ## .deflt. ## typename ## _val  = val; \
-   Params. ## nam ## .comment = commnt;
+   Params.nam.loaded = False; \
+   Params.nam.name = #nam; \
+   Params.nam.deflt.typename ## _val  = val; \
+   Params.nam.comment = commnt;
 
 #define INIT_PARAM_STRING( nam, val, commnt ) \
    INIT_PARAM( nam, val, string, commnt ); \
-   Params. ## nam ## .type = PARAM_STRING;
+   Params.nam.type = PARAM_STRING;
 
 #define INIT_PARAM_CHAR( nam, val, commnt ) \
    INIT_PARAM( nam, val, char, commnt ); \
-   Params. ## nam ## .type = PARAM_CHAR;
+   Params.nam.type = PARAM_CHAR;
 
 #define INIT_PARAM_INT( nam, val, commnt ) \
    INIT_PARAM( nam, val, int, commnt ); \
-   Params. ## nam ## .type = PARAM_INT;
+   Params.nam.type = PARAM_INT;
 
 #define INIT_PARAM_BOOL( nam, val, commnt ) \
    INIT_PARAM( nam, val, bool, commnt ); \
-   Params. ## nam ## .type = PARAM_BOOL;
+   Params.nam.type = PARAM_BOOL;
 
 
 /*
@@ -310,13 +310,13 @@
  */
 #define FN_PARAM( name, typename, type ) \
     type getparam_ ## name() { \
-        if ( !Params. ## name ## .loaded ) { \
-            fetch_param_ ## typename( &( Params. ## name ) ); \
+        if ( !Params.name.loaded ) { \
+            fetch_param_ ## typename( &( Params.name ) ); \
         } \
-        return Params. ## name ## .val. ## typename ## _val; \
+        return Params.name.val.typename ## _val; \
     } \
     void setparam_ ## name( type val) { \
-        set_param_ ## typename( &( Params. ## name ), val ); } 
+        set_param_ ## typename( &( Params.name ), val ); } 
 
 #define FN_PARAM_STRING( name ) \
     FN_PARAM( name, string, char* )
