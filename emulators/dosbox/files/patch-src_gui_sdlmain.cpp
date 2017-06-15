*** src/gui/sdlmain.cpp.orig	Mon Mar  6 03:02:24 2017
--- src/gui/sdlmain.cpp	Mon Mar  6 03:03:21 2017
***************
*** 1134,1143 ****
  #endif
  	const char * gl_ext = (const char *)glGetString (GL_EXTENSIONS);
  	if(gl_ext && *gl_ext){
! 		sdl.opengl.packed_pixel=(strstr(gl_ext,"EXT_packed_pixels") > 0);
! 		sdl.opengl.paletted_texture=(strstr(gl_ext,"EXT_paletted_texture") > 0);
  #if defined(NVIDIA_PixelDataRange)
! 		sdl.opengl.pixel_data_range=(strstr(gl_ext,"GL_NV_pixel_data_range") >0 ) &&
  			glPixelDataRangeNV && db_glAllocateMemoryNV && db_glFreeMemoryNV;
  		sdl.opengl.pixel_data_range = 0;
  #endif
--- 1134,1143 ----
  #endif
  	const char * gl_ext = (const char *)glGetString (GL_EXTENSIONS);
  	if(gl_ext && *gl_ext){
! 		sdl.opengl.packed_pixel=(strstr(gl_ext,"EXT_packed_pixels") != 0);
! 		sdl.opengl.paletted_texture=(strstr(gl_ext,"EXT_paletted_texture") != 0);
  #if defined(NVIDIA_PixelDataRange)
! 		sdl.opengl.pixel_data_range=(strstr(gl_ext,"GL_NV_pixel_data_range") != 0 ) &&
  			glPixelDataRangeNV && db_glAllocateMemoryNV && db_glFreeMemoryNV;
  		sdl.opengl.pixel_data_range = 0;
  #endif
