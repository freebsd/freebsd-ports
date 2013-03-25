--- plugins/mathview/itex2mml/itex2MML.y.orig	2010-06-08 23:03:23.000000000 +0200
+++ plugins/mathview/itex2mml/itex2MML.y	2010-06-08 23:07:10.000000000 +0200
@@ -260,7 +260,7 @@
 
  /* Create a hex character reference string corresponding to code
   */
- char * itex2MML_character_reference (unsigned long int code)
+ char * itex2MML_character_reference (unsigned int code)
    {
 #define ENTITY_LENGTH 10
      char * entity = (char *) malloc(ENTITY_LENGTH);
