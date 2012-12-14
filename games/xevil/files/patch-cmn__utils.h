--- cmn/utils.h.orig	2012-05-27 06:52:31.000000000 +0900
+++ cmn/utils.h	2012-05-27 06:53:11.000000000 +0900
@@ -159,7 +159,7 @@
 
 typedef int GameStyleType;
 // Possible values of GameStyleType.
-enum {SCENARIOS,LEVELS_ONLY,KILL,DUEL,EXTENDED,TRAINING,LEVELS};
+enum {SCENARIOS,LEVELS_ONLY,KILL,DUEL,EXTENDED,TRAINING,LEVELS,NUM_GAME_STYLES};
 
 
 
@@ -237,13 +237,13 @@
   /* EFFECTS: Wrapper for C library strcmp().  Return 0 if strings are the
      same. */
 
-  static char* strchr(const char* cs,int c)
+  static const char* strchr(const char* cs,int c)
     {return ::strchr(cs,c);}
 
-  static char* strrchr(const char* cs,int c)
+  static const char* strrchr(const char* cs,int c)
     {return ::strrchr(cs,c);}
 
-  static char* strstr(const char* cs,const char* ct)
+  static const char* strstr(const char* cs,const char* ct)
     {return ::strstr(cs,ct);}
 
   static void strcpy(char* s,const char* ct)
