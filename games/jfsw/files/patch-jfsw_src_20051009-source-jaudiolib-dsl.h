--- jfsw_src_20051009/source/jaudiolib/dsl.h.orig	1970-01-01 01:00:00.000000000 +0100
+++ jfsw_src_20051009/source/jaudiolib/dsl.h	2005-10-10 15:02:08.000000000 +0200
@@ -0,0 +1,50 @@
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
+#ifndef AUDIOLIB__DSL_H
+#define AUDIOLIB__DSL_H
+
+#define MONO_8BIT    0
+#define STEREO      1
+#define SIXTEEN_BIT 2
+#define STEREO_16BIT ( STEREO | SIXTEEN_BIT )
+
+enum DSL_ERRORS
+   {
+   DSL_Warning = -2,
+   DSL_Error = -1,
+   DSL_Ok = 0,
+   DSL_SDLInitFailure,
+   DSL_MixerActive,
+   DSL_MixerInitFailure
+   };
+
+char *DSL_ErrorString( int ErrorNumber );
+int   DSL_Init( void );
+void  DSL_StopPlayback( void );
+unsigned DSL_GetPlaybackRate( void );
+int   DSL_BeginBufferedPlayback( char *BufferStart,
+      int BufferSize, int NumDivisions, unsigned SampleRate,
+      int MixMode, void ( *CallBackFunc )( void ) );
+void  DSL_Shutdown( void );
+
+#endif
