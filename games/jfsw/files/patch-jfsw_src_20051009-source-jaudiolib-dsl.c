--- jfsw_src_20051009/source/jaudiolib/dsl.c.orig	1970-01-01 01:00:00.000000000 +0100
+++ jfsw_src_20051009/source/jaudiolib/dsl.c	2005-10-10 15:02:08.000000000 +0200
@@ -0,0 +1,257 @@
+/*
+Copyright (C) 2003-2004 Ryan C. Gordon. and James Bentler
+
+This program is free software; you can redistribute it and/or
+modify it under the terms of the GNU General Public License
+as published by the Free Software Foundation; either version 2
+of the License, or (at your option) any later version.
+
+This program is distributed in the hope that it will be useful,
+but WITHOUT ANY WARRANTY; without even the implied warranty of
+MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
+
+See the GNU General Public License for more details.
+
+You should have received a copy of the GNU General Public License
+along with this program; if not, write to the Free Software
+Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
+
+Originally written by Ryan C. Gordon. (icculus@clutteredmind.org)
+Adapted to work with JonoF's port by James Bentler (bentler@cs.umn.edu)
+
+*/
+#include <stdlib.h>
+#include <string.h>
+
+#include "dsl.h"
+#include "util.h"
+
+#include "SDL.h"
+#include "SDL_mixer.h"
+
+extern volatile int MV_MixPage;
+
+static int DSL_ErrorCode = DSL_Ok;
+
+static int mixer_initialized;
+
+static void ( *_CallBackFunc )( void );
+static volatile char *_BufferStart;
+static int _BufferSize;
+static int _NumDivisions;
+static int _SampleRate;
+static int _remainder;
+
+static Mix_Chunk *blank;
+static unsigned char *blank_buf;
+
+/*
+possible todo ideas: cache sdl/sdl mixer error messages.
+*/
+
+char *DSL_ErrorString( int ErrorNumber )
+{
+   char *ErrorString;
+   
+   switch (ErrorNumber) {
+       case DSL_Warning:
+       case DSL_Error:
+           ErrorString = DSL_ErrorString(DSL_ErrorCode);
+           break;
+       
+       case DSL_Ok:
+           ErrorString = "SDL Driver ok.";
+           break;
+       
+       case DSL_SDLInitFailure:
+           ErrorString = "SDL Audio initialization failed.";
+           break;
+       
+       case DSL_MixerActive:
+           ErrorString = "SDL Mixer already initialized.";
+           break;  
+   
+       case DSL_MixerInitFailure:
+           ErrorString = "SDL Mixer initialization failed.";
+           break;
+           
+       default:
+           ErrorString = "Unknown SDL Driver error.";
+           break;
+   }
+   
+   return ErrorString;
+}
+
+static void DSL_SetErrorCode(int ErrorCode)
+{
+   DSL_ErrorCode = ErrorCode;
+}
+
+int DSL_Init( void )
+{
+   DSL_SetErrorCode(DSL_Ok);
+   
+   if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0) {
+       DSL_SetErrorCode(DSL_SDLInitFailure);
+       
+       return DSL_Error;
+   }
+   
+   return DSL_Ok;
+}
+
+void DSL_Shutdown( void )
+{
+   DSL_StopPlayback();
+}
+
+static void mixer_callback(int chan, void *stream, int len, void *udata)
+{
+   Uint8 *stptr;
+   Uint8 *fxptr;
+   int copysize;
+   
+   /* len should equal _BufferSize, else this is screwed up */
+
+   stptr = (Uint8 *)stream;
+   
+   if (_remainder > 0) {
+       copysize = min(len, _remainder);
+       
+       fxptr = (Uint8 *)(&_BufferStart[MV_MixPage * 
+           _BufferSize]);
+       
+       memcpy(stptr, fxptr+(_BufferSize-_remainder), copysize);
+       
+       len -= copysize;
+       _remainder -= copysize;
+       
+       stptr += copysize;
+   }
+   
+   while (len > 0) {
+       /* new buffer */
+       
+       _CallBackFunc();
+       
+       fxptr = (Uint8 *)(&_BufferStart[MV_MixPage * 
+           _BufferSize]);
+
+       copysize = min(len, _BufferSize);
+       
+       memcpy(stptr, fxptr, copysize);
+       
+       len -= copysize;
+       
+       stptr += copysize;
+   }
+   
+   _remainder = len;
+}
+
+int   DSL_BeginBufferedPlayback( char *BufferStart,
+      int BufferSize, int NumDivisions, unsigned SampleRate,
+      int MixMode, void ( *CallBackFunc )( void ) )
+{
+   Uint16 format;
+   Uint8 *tmp;
+   int channels;
+   int chunksize;
+       
+   if (mixer_initialized) {
+       DSL_SetErrorCode(DSL_MixerActive);
+       
+       return DSL_Error;
+   }
+   
+   _CallBackFunc = CallBackFunc;
+   _BufferStart = BufferStart;
+   _BufferSize = (BufferSize / NumDivisions);
+   _NumDivisions = NumDivisions;
+   _SampleRate = SampleRate;
+
+   _remainder = 0;
+   
+   format = (MixMode & SIXTEEN_BIT) ? AUDIO_S16SYS : AUDIO_U8;
+   channels = (MixMode & STEREO) ? 2 : 1;
+
+/*
+   23ms is typically ideal (11025,22050,44100)
+   46ms isn't bad
+*/
+   
+   chunksize = 512;
+   
+   if (SampleRate >= 16000) chunksize *= 2;
+   if (SampleRate >= 32000) chunksize *= 2;
+   
+/* 
+// SDL mixer does this already
+   if (MixMode & SIXTEEN_BIT) chunksize *= 2;
+   if (MixMode & STEREO) chunksize *= 2;
+*/
+   
+   if (Mix_OpenAudio(SampleRate, format, channels, chunksize) < 0) {
+       DSL_SetErrorCode(DSL_MixerInitFailure);
+       
+       return DSL_Error;
+   }
+
+/*
+   Mix_SetPostMix(mixer_callback, NULL);
+*/
+   /* have to use a channel because postmix will overwrite the music... */
+   Mix_RegisterEffect(0, mixer_callback, NULL, NULL);
+   
+   /* create a dummy sample just to allocate that channel */
+   blank_buf = (Uint8 *)malloc(4096);
+   memset(blank_buf, 0, 4096);
+   
+   blank = Mix_QuickLoad_RAW(blank_buf, 4096);
+       
+   Mix_PlayChannel(0, blank, -1);
+   
+   mixer_initialized = 1;
+   
+   return DSL_Ok;
+}
+
+void DSL_StopPlayback( void )
+{
+   if (mixer_initialized) {
+       Mix_HaltChannel(0);
+   }
+   
+   if (blank != NULL) {
+       Mix_FreeChunk(blank);
+   }
+   
+   blank = NULL;
+   
+   if (blank_buf  != NULL) {
+       free(blank_buf);
+   }
+   
+   blank_buf = NULL;
+   
+   if (mixer_initialized) {
+       Mix_CloseAudio();
+   }
+   
+   mixer_initialized = 0;
+}
+
+unsigned DSL_GetPlaybackRate( void )
+{
+   return _SampleRate;
+}
+
+unsigned long DisableInterrupts( void )
+{
+   return 0;
+}
+
+void RestoreInterrupts( unsigned long flags )
+{
+}
