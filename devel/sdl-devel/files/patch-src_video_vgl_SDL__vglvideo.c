
$FreeBSD$

--- /dev/null	Mon Jan 22 20:53:09 2001
+++ src/video/vgl/SDL_vglvideo.c	Mon Jan 22 20:04:39 2001
@@ -0,0 +1,444 @@
+/*
+    SDL - Simple DirectMedia Layer
+    Copyright (C) 1997, 1998, 1999, 2000  Sam Lantinga
+
+    This library is free software; you can redistribute it and/or
+    modify it under the terms of the GNU Library General Public
+    License as published by the Free Software Foundation; either
+    version 2 of the License, or (at your option) any later version.
+
+    This library is distributed in the hope that it will be useful,
+    but WITHOUT ANY WARRANTY; without even the implied warranty of
+    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
+    Library General Public License for more details.
+
+    You should have received a copy of the GNU Library General Public
+    License along with this library; if not, write to the Free
+    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
+
+    Sam Lantinga
+    slouken@devolution.com
+*/
+
+#ifdef SAVE_RCSID
+static char rcsid =
+ "@(#) $Id: SDL_vglvideo.c,v 1.1 2001/01/20 18:21:25 root Exp root $";
+#endif
+
+/* libvga based SDL video driver implementation.
+*/
+
+#include <stdlib.h>
+#include <stdio.h>
+#include <unistd.h>
+#include <sys/stat.h>
+
+#include <sys/fbio.h>
+#include <sys/consio.h>
+#include <sys/kbio.h>
+#include <vgl.h>
+
+#include "SDL.h"
+#include "SDL_error.h"
+#include "SDL_video.h"
+#include "SDL_mouse.h"
+#include "SDL_sysvideo.h"
+#include "SDL_pixels_c.h"
+#include "SDL_events_c.h"
+#include "SDL_vglvideo.h"
+#include "SDL_vglevents_c.h"
+#include "SDL_vglmouse_c.h"
+
+
+static VGLMode *VGLCurMode = NULL;
+
+/* Initialization/Query functions */
+static int VGL_VideoInit(_THIS, SDL_PixelFormat *vformat);
+static SDL_Rect **VGL_ListModes(_THIS, SDL_PixelFormat *format, Uint32 flags);
+static SDL_Surface *VGL_SetVideoMode(_THIS, SDL_Surface *current, int width, int height, int bpp, Uint32 flags);
+static int VGL_SetColors(_THIS, int firstcolor, int ncolors,
+			  SDL_Color *colors);
+static void VGL_VideoQuit(_THIS);
+
+/* Hardware surface functions */
+static int VGL_AllocHWSurface(_THIS, SDL_Surface *surface);
+static int VGL_LockHWSurface(_THIS, SDL_Surface *surface);
+static int VGL_FlipHWSurface(_THIS, SDL_Surface *surface);
+static void VGL_UnlockHWSurface(_THIS, SDL_Surface *surface);
+static void VGL_FreeHWSurface(_THIS, SDL_Surface *surface);
+
+/* VGL driver bootstrap functions */
+
+static int VGL_Available(void)
+{
+	/* Check to see if we are root and stdin is a virtual console */
+	int console;
+
+	console = STDIN_FILENO;
+	if ( console >= 0 ) {
+		struct stat sb;
+		struct vt_mode dummy;
+
+		if ( (fstat(console, &sb) < 0) ||
+		     (ioctl(console, VT_GETMODE, &dummy) < 0) ) {
+			console = -1;
+		}
+	}
+	return((geteuid() == 0) && (console >= 0));
+}
+
+static void VGL_DeleteDevice(SDL_VideoDevice *device)
+{
+	free(device->hidden);
+	free(device);
+}
+
+static SDL_VideoDevice *VGL_CreateDevice(int devindex)
+{
+	SDL_VideoDevice *device;
+
+	/* Initialize all variables that we clean on shutdown */
+	device = (SDL_VideoDevice *)malloc(sizeof(SDL_VideoDevice));
+	if ( device ) {
+		memset(device, 0, (sizeof *device));
+		device->hidden = (struct SDL_PrivateVideoData *)
+				  malloc((sizeof *device->hidden));
+	}
+	if ( (device == NULL) || (device->hidden == NULL) ) {
+		SDL_OutOfMemory();
+		if ( device ) {
+			free(device);
+		}
+		return(0);
+	}
+	memset(device->hidden, 0, (sizeof *device->hidden));
+
+	/* Set the function pointers */
+	device->VideoInit = VGL_VideoInit;
+	device->ListModes = VGL_ListModes;
+	device->SetVideoMode = VGL_SetVideoMode;
+	device->SetColors = VGL_SetColors;
+	device->UpdateRects = NULL;
+	device->VideoQuit = VGL_VideoQuit;
+	device->AllocHWSurface = VGL_AllocHWSurface;
+	device->CheckHWBlit = NULL;
+	device->FillHWRect = NULL;
+	device->SetHWColorKey = NULL;
+	device->SetHWAlpha = NULL;
+	device->LockHWSurface = VGL_LockHWSurface;
+	device->UnlockHWSurface = VGL_UnlockHWSurface;
+	device->FlipHWSurface = NULL;
+	device->FreeHWSurface = VGL_FreeHWSurface;
+	device->SetIcon = NULL;
+	device->SetCaption = NULL;
+	device->GetWMInfo = NULL;
+	device->FreeWMCursor = VGL_FreeWMCursor;
+	device->CreateWMCursor = VGL_CreateWMCursor;
+	device->ShowWMCursor = VGL_ShowWMCursor;
+	device->WarpWMCursor = VGL_WarpWMCursor;
+	device->InitOSKeymap = VGL_InitOSKeymap;
+	device->PumpEvents = VGL_PumpEvents;
+
+	device->free = VGL_DeleteDevice;
+
+	return device;
+}
+
+VideoBootStrap VGL_bootstrap = {
+	"vgl", "FreeBSD libVGL",
+	VGL_Available, VGL_CreateDevice
+};
+
+static int VGL_AddMode(_THIS, VGLMode *inmode)
+{
+	SDL_Rect *mode;
+
+	int i, index;
+	int next_mode;
+
+	/* Check to see if we already have this mode */
+	if (inmode->Depth < 8) {  /* Not supported */
+		return 0;
+	}
+	index = ((inmode->Depth + 7) / 8) - 1;
+	for (i=0; i<SDL_nummodes[index]; ++i) {
+		mode = SDL_modelist[index][i];
+		if ((mode->w == inmode->ModeInfo.Xsize) &&
+		    (mode->h == inmode->ModeInfo.Ysize))
+			return 0;
+	}
+
+	/* Set up the new video mode rectangle */
+	mode = (SDL_Rect *)malloc(sizeof *mode);
+	if (mode == NULL) {
+		SDL_OutOfMemory();
+		return -1;
+	}
+	mode->x = 0;
+	mode->y = 0;
+	mode->w = inmode->ModeInfo.Xsize;
+	mode->h = inmode->ModeInfo.Ysize;
+
+	/* Allocate the new list of modes, and fill in the new mode */
+	next_mode = SDL_nummodes[index];
+	SDL_modelist[index] = (SDL_Rect **)
+		realloc(SDL_modelist[index], (1+next_mode+1)*sizeof(SDL_Rect *));
+	if (SDL_modelist[index] == NULL) {
+		SDL_OutOfMemory();
+		SDL_nummodes[index] = 0;
+		free(mode);
+		return -1;
+	}
+	SDL_modelist[index][next_mode] = mode;
+	SDL_modelist[index][next_mode+1] = NULL;
+	SDL_nummodes[index]++;
+
+	return 0;
+}
+
+static void VGL_UpdateVideoInfo(_THIS)
+{
+	this->info.wm_available = 0;
+	this->info.hw_available = 1;
+	this->info.video_mem = 0;
+	if (VGLCurMode == NULL) {
+		return;
+	}
+	if (VGLCurMode->ModeInfo.PixelBytes > 0) {
+		this->info.video_mem = VGLCurMode->ModeInfo.PixelBytes *
+				       VGLCurMode->ModeInfo.Xsize *
+				       VGLCurMode->ModeInfo.Ysize;
+	}
+}
+
+int VGL_VideoInit(_THIS, SDL_PixelFormat *vformat)
+{
+	int i;
+	int total_modes;
+	VGLMode **modes;
+
+	/* Initialize all variables that we clean on shutdown */
+	for ( i=0; i<NUM_MODELISTS; ++i ) {
+		SDL_nummodes[i] = 0;
+		SDL_modelist[i] = NULL;
+	}
+
+	/* Enable mouse and keyboard support */
+	if (VGLKeyboardInit(VGL_CODEKEYS) != 0) {
+		SDL_SetError("Unable to initialize keyboard");
+		return -1;
+	}
+	if (VGL_initkeymaps(STDIN_FILENO) != 0) {
+		SDL_SetError("Unable to initialize keymap");
+		return -1;
+	}
+	if (VGL_initmouse(STDIN_FILENO) != 0) {
+		SDL_SetError("Unable to initialize mouse");
+		return -1;
+	}
+//	if (VGLMouseInit(VGL_MOUSEHIDE) != 0) {
+//		SDL_SetError("Unable to initialize mouse");
+//		return -1;
+//	}
+
+	/* Determine the screen depth */
+	if (VGLCurMode != NULL)
+		vformat->BitsPerPixel = VGLCurMode->Depth;
+	else
+		vformat->BitsPerPixel = 16;	/* Good default */
+
+	/* Query for the list of available video modes */
+	total_modes = 0;
+	modes = VGLListModes(-1, V_INFO_MM_DIRECT | V_INFO_MM_PACKED);
+	for (i = 0; modes[i] != NULL; i++) {
+		if ((modes[i]->ModeInfo.Type == VIDBUF8) ||
+		    (modes[i]->ModeInfo.Type == VIDBUF16) ||
+		    (modes[i]->ModeInfo.Type == VIDBUF32)) {
+			VGL_AddMode(this, modes[i]);
+			total_modes++;
+		}
+	}
+	if (total_modes == 0) {
+		SDL_SetError("No linear video modes available");
+		return -1;
+	}
+
+	/* Fill in our hardware acceleration capabilities */
+	VGL_UpdateVideoInfo(this);
+
+	/* Create the hardware surface lock mutex */
+	hw_lock = SDL_CreateMutex();
+	if (hw_lock == NULL) {
+		SDL_SetError("Unable to create lock mutex");
+		VGL_VideoQuit(this);
+		return -1;
+	}
+
+	/* We're done! */
+	return 0;
+}
+
+SDL_Rect **VGL_ListModes(_THIS, SDL_PixelFormat *format, Uint32 flags)
+{
+	return SDL_modelist[((format->BitsPerPixel+7)/8)-1];
+}
+
+/* Various screen update functions available */
+static void VGL_DirectUpdate(_THIS, int numrects, SDL_Rect *rects);
+static void VGL_BankedUpdate(_THIS, int numrects, SDL_Rect *rects);
+
+SDL_Surface *VGL_SetVideoMode(_THIS, SDL_Surface *current,
+				int width, int height, int bpp, Uint32 flags)
+{
+	int mode_found;
+	int i;
+	VGLMode **modes;
+
+	modes = VGLListModes(bpp, V_INFO_MM_DIRECT | V_INFO_MM_PACKED);
+	mode_found = 0;
+	for (i = 0; modes[i] != NULL; i++) {
+		if ((modes[i]->ModeInfo.Xsize == width) &&
+		    (modes[i]->ModeInfo.Ysize == height) &&
+		    ((modes[i]->ModeInfo.Type == VIDBUF8) ||
+		     (modes[i]->ModeInfo.Type == VIDBUF16) ||
+		     (modes[i]->ModeInfo.Type == VIDBUF32))) {
+			mode_found = 1;
+			break;
+		}
+	}
+	if (mode_found == 0) {
+		SDL_SetError("No matching video mode found");
+		return NULL;
+	}
+
+	/* Shutdown previous videomode (if any) */
+	if (VGLCurMode != NULL)
+		VGLEnd();
+
+	/* Try to set the requested linear video mode */
+	if (VGLInit(modes[i]->ModeId) != 0) {
+		SDL_SetError("Unable to switch to requested mode");
+		return NULL;
+	}
+	VGLCurMode = realloc(VGLCurMode, sizeof(VGLMode));
+	VGLCurMode->ModeInfo = *VGLDisplay;
+	VGLCurMode->Depth = modes[i]->Depth;
+	VGLCurMode->ModeId = modes[i]->ModeId;
+
+	/* Workaround a bug in libvgl */
+	if (VGLCurMode->ModeInfo.PixelBytes == 0)
+		(VGLCurMode->ModeInfo.PixelBytes = 1);
+
+	current->flags = (SDL_FULLSCREEN | SDL_HWSURFACE);
+	if (VGLCurMode->ModeInfo.Type == VIDBUF8)
+		current->flags |= SDL_HWPALETTE;
+	current->w = VGLCurMode->ModeInfo.Xsize;
+	current->h = VGLCurMode->ModeInfo.Ysize;
+	current->pixels = VGLCurMode->ModeInfo.Bitmap;
+	current->pitch = VGLCurMode->ModeInfo.Xsize * VGLCurMode->ModeInfo.PixelBytes;
+
+	/* FIXME - should set colormasks for bpp > 8*/
+	if (! SDL_ReallocFormat(current, modes[i]->Depth, 0, 0, 0, 0)) {
+		return NULL;
+	}
+
+	/* Update hardware acceleration info */
+	VGL_UpdateVideoInfo(this);
+
+	/* Set the blit function */
+	this->UpdateRects = VGL_DirectUpdate;
+
+	/* We're done */
+	return current;
+}
+
+/* We don't actually allow hardware surfaces other than the main one */
+static int VGL_AllocHWSurface(_THIS, SDL_Surface *surface)
+{
+	return -1;
+}
+static void VGL_FreeHWSurface(_THIS, SDL_Surface *surface)
+{
+	return;
+}
+
+/* We need to wait for vertical retrace on page flipped displays */
+static int VGL_LockHWSurface(_THIS, SDL_Surface *surface)
+{
+	if (surface == SDL_VideoSurface) {
+		SDL_mutexP(hw_lock);
+	}
+	return 0;
+}
+static void VGL_UnlockHWSurface(_THIS, SDL_Surface *surface)
+{
+	if (surface == SDL_VideoSurface) {
+		SDL_mutexV(hw_lock);
+	}
+}
+
+static int VGL_FlipHWSurface(_THIS, SDL_Surface *surface)
+{
+	return 0;
+}
+
+static void VGL_DirectUpdate(_THIS, int numrects, SDL_Rect *rects)
+{
+	return;
+}
+
+static void VGL_BankedUpdate(_THIS, int numrects, SDL_Rect *rects)
+{
+	return;
+}
+
+int VGL_SetColors(_THIS, int firstcolor, int ncolors, SDL_Color *colors)
+{
+        int i;
+
+	for(i = 0; i < ncolors; i++) {
+	        VGLSetPaletteIndex(firstcolor + i,
+			       colors[i].r>>2,
+			       colors[i].g>>2,
+			       colors[i].b>>2);
+	}
+	return 1;
+}
+
+/* Note:  If we are terminated, this could be called in the middle of
+   another SDL video routine -- notably UpdateRects.
+*/
+void VGL_VideoQuit(_THIS)
+{
+	int i, j;
+
+	/* Reset the console video mode */
+	VGLKeyboardEnd();
+	VGLEnd();
+	if (VGLCurMode != NULL) {
+		free(VGLCurMode);
+		VGLCurMode = NULL;
+	}
+
+	/* Clear the lock mutex */
+	if (hw_lock != NULL) {
+		SDL_DestroyMutex(hw_lock);
+		hw_lock = NULL;
+	}
+
+	/* Free video mode lists */
+	for (i = 0; i < NUM_MODELISTS; i++) {
+		if (SDL_modelist[i] != NULL) {
+			for (j = 0; SDL_modelist[i][j] != NULL; ++j) {
+				free(SDL_modelist[i][j]);
+			}
+			free(SDL_modelist[i]);
+			SDL_modelist[i] = NULL;
+		}
+	}
+
+	if ( this->screen && (this->screen->flags & SDL_HWSURFACE) ) {
+	/* Direct screen access, not a memory buffer */
+		this->screen->pixels = NULL;
+	}
+}
