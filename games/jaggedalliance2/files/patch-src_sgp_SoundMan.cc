--- src/sgp/SoundMan.cc.orig	2022-04-27 09:14:13 UTC
+++ src/sgp/SoundMan.cc
@@ -696,7 +696,7 @@ size_t MiniaudioReadProc(ma_decoder* pDecoder, void* p
 	return SDL_RWread(rwOps, pBufferOut, sizeof(UINT8), bytesToRead);
 }
 
-ma_bool32 MiniaudioSeekProc(ma_decoder* pDecoder, int byteOffset, ma_seek_origin origin) {
+ma_bool32 MiniaudioSeekProc(ma_decoder* pDecoder, ma_int64 byteOffset, ma_seek_origin origin) {
 	auto rwOps = (SDL_RWops*)pDecoder->pUserData;
 	auto sdlOrigin = RW_SEEK_SET;
 	if (origin == ma_seek_origin::ma_seek_origin_current) {
