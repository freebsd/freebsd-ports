--- gl.c.orig	Sat Aug 13 01:51:49 2005
+++ gl.c	Thu Sep  1 02:19:45 2005
@@ -40,7 +40,7 @@
 #include <GL/glu.h>
 #include <string.h>
 #include "apool.h"
-#include <linux/param.h>
+#include <sys/param.h>
 #include <sys/time.h>
 
 #ifndef M_PI
@@ -452,14 +452,14 @@
 int LoadGLTextures( void ) /* ebenfalls basierend auf einem Nehe Tutorial */
  {                         /* aber für mehrere Texturen angepasst und erweitert f. Mipmapping, Cube-Textures, usw.*/
  int i;
- char txt[80];
+ char txt[PATH_MAX];
  SDL_Surface *TextureImage[ANZ_TEXTURES];
  memset(TextureImage,0,sizeof(void *)*ANZ_TEXTURES);			
  texture = malloc((sizeof(int) * ANZ_TEXTURES));
  
  for(i=0;i<BALLS;i++)
    {
-   sprintf(txt,"textures-hi/%d.bmp",i);
+   sprintf(txt,DATADIR"/textures-hi/%d.bmp",i);
    if( !(TextureImage[i]=LoadBMP(txt)) ) 
     {
     printf("can't find %d of hd textures\n",i);
@@ -469,7 +469,7 @@
 
  for(i=BALLS;i<2*BALLS;i++)
    {
-   sprintf(txt,"textures-lo/%d.bmp",i-BALLS);
+   sprintf(txt,DATADIR"/textures-lo/%d.bmp",i-BALLS);
    if( !(TextureImage[i]=LoadBMP(txt)) ) 
     {
     printf("can't find %d of ld textures\n",i-BALLS);
@@ -477,11 +477,11 @@
     }
    }
  
- if( !(TextureImage[i++]=LoadBMP("textures-hi/Font.bmp")) ) return FALSE; 
- if( !(TextureImage[i++]=LoadBMP("textures-hi/Holz.bmp")) ) return FALSE; 
- if( !(TextureImage[i++]=LoadBMP("textures-hi/Marmor.bmp")) ) return FALSE; 
- if( !(TextureImage[i++]=LoadBMP("textures-hi/Tuch.bmp")) ) return FALSE; 
- if( !(TextureImage[i++]=LoadBMP("textures-hi/Env.bmp")) ) return FALSE; 
+ if( !(TextureImage[i++]=LoadBMP(DATADIR"/textures-hi/Font.bmp")) ) return FALSE; 
+ if( !(TextureImage[i++]=LoadBMP(DATADIR"/textures-hi/Holz.bmp")) ) return FALSE; 
+ if( !(TextureImage[i++]=LoadBMP(DATADIR"/textures-hi/Marmor.bmp")) ) return FALSE; 
+ if( !(TextureImage[i++]=LoadBMP(DATADIR"/textures-hi/Tuch.bmp")) ) return FALSE; 
+ if( !(TextureImage[i++]=LoadBMP(DATADIR"/textures-hi/Env.bmp")) ) return FALSE; 
  
  glGenTextures(ANZ_TEXTURES, &texture[0]);
  for (i=0; i<ANZ_TEXTURES; i++)				
