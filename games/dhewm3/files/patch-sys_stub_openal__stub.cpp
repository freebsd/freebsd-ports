--- sys/stub/openal_stub.cpp.orig	2024-08-03 03:52:42 UTC
+++ sys/stub/openal_stub.cpp
@@ -32,53 +32,53 @@ extern "C" {
 
 extern "C" {
 
-AL_API ALenum AL_APIENTRY alGetError() {
+AL_API ALenum AL_APIENTRY alGetError() AL_API_NOEXCEPT {
 	return AL_NO_ERROR;
 }
 
-AL_API ALboolean AL_APIENTRY alIsSource( ALuint sid ) {
+AL_API ALboolean AL_APIENTRY alIsSource( ALuint sid ) AL_API_NOEXCEPT {
 	return AL_FALSE;
 }
 
-AL_API void AL_APIENTRY alGenBuffers( ALsizei n, ALuint* buffers ) { }
+AL_API void AL_APIENTRY alGenBuffers( ALsizei n, ALuint* buffers ) AL_API_NOEXCEPT { }
 
-AL_API void AL_APIENTRY alSourceStop( ALuint sid ) { }
+AL_API void AL_APIENTRY alSourceStop( ALuint sid ) AL_API_NOEXCEPT { }
 
-AL_API void AL_APIENTRY alGetSourcei( ALuint sid,  ALenum pname, ALint* value ) { }
+AL_API void AL_APIENTRY alGetSourcei( ALuint sid,  ALenum pname, ALint* value ) AL_API_NOEXCEPT { }
 
-AL_API void AL_APIENTRY alSource3i( ALuint sid, ALenum param, ALint value1, ALint value2, ALint value3 ) { }
+AL_API void AL_APIENTRY alSource3i( ALuint sid, ALenum param, ALint value1, ALint value2, ALint value3 ) AL_API_NOEXCEPT { }
 
 
-AL_API const ALchar* AL_APIENTRY alGetString( ALenum param ) {
+AL_API const ALchar* AL_APIENTRY alGetString( ALenum param ) AL_API_NOEXCEPT {
 	return "";
 }
 
-AL_API ALint AL_APIENTRY alGetInteger( ALenum param ) { return 0; }
+AL_API ALint AL_APIENTRY alGetInteger( ALenum param ) AL_API_NOEXCEPT { return 0; }
 
-ALC_API void ALC_APIENTRY alcSuspendContext( ALCcontext *alcHandle ) { }
+ALC_API void ALC_APIENTRY alcSuspendContext( ALCcontext *alcHandle ) AL_API_NOEXCEPT { }
 
-ALC_API ALCdevice * ALC_APIENTRY alcOpenDevice( const ALchar *tokstr ) {
+ALC_API ALCdevice * ALC_APIENTRY alcOpenDevice( const ALchar *tokstr ) AL_API_NOEXCEPT {
 	return NULL;
 }
 
-ALC_API ALCboolean ALC_APIENTRY alcIsExtensionPresent( ALCdevice *device, const ALCchar *extname ) {
+ALC_API ALCboolean ALC_APIENTRY alcIsExtensionPresent( ALCdevice *device, const ALCchar *extname ) AL_API_NOEXCEPT {
 	return AL_FALSE;
 }
 
-ALC_API void ALC_APIENTRY alcGetIntegerv(ALCdevice *device, ALCenum param, ALCsizei size, ALCint *values) {}
+ALC_API void ALC_APIENTRY alcGetIntegerv(ALCdevice *device, ALCenum param, ALCsizei size, ALCint *values) AL_API_NOEXCEPT {}
 
-ALC_API ALCenum ALC_APIENTRY alcGetError(ALCdevice *device) {
+ALC_API ALCenum ALC_APIENTRY alcGetError(ALCdevice *device) AL_API_NOEXCEPT {
 	return ALC_NO_ERROR;
 }
 
-ALC_API void* ALC_APIENTRY alcGetProcAddress(ALCdevice *device, const ALCchar *funcname) {
+ALC_API void* ALC_APIENTRY alcGetProcAddress(ALCdevice *device, const ALCchar *funcname) AL_API_NOEXCEPT {
 	return NULL;
 }
 
 
-AL_API void AL_APIENTRY alDeleteBuffers( ALsizei n, const ALuint* buffers ) { }
+AL_API void AL_APIENTRY alDeleteBuffers( ALsizei n, const ALuint* buffers ) AL_API_NOEXCEPT { }
 
-AL_API ALboolean AL_APIENTRY alIsExtensionPresent( const ALchar* fname ) {
+AL_API ALboolean AL_APIENTRY alIsExtensionPresent( const ALchar* fname ) AL_API_NOEXCEPT {
 	return AL_FALSE;
 }
 
@@ -86,63 +86,63 @@ AL_API void AL_APIENTRY alBufferData( ALuint   buffer,
 									ALenum   format,
 									const ALvoid*    data,
 									ALsizei  size,
-									ALsizei  freq ) { }
+									ALsizei  freq ) AL_API_NOEXCEPT { }
 
-ALC_API ALCboolean ALC_APIENTRY alcMakeContextCurrent( ALCcontext *alcHandle ) {
+ALC_API ALCboolean ALC_APIENTRY alcMakeContextCurrent( ALCcontext *alcHandle ) AL_API_NOEXCEPT {
 	return 0;
 }
 
-ALC_API ALCvoid ALC_APIENTRY alcProcessContext( ALCcontext *alcHandle ) {
+ALC_API ALCvoid ALC_APIENTRY alcProcessContext( ALCcontext *alcHandle ) AL_API_NOEXCEPT {
 	return;
 }
 
-ALC_API ALCvoid ALC_APIENTRY alcDestroyContext( ALCcontext *alcHandle ) {
+ALC_API ALCvoid ALC_APIENTRY alcDestroyContext( ALCcontext *alcHandle ) AL_API_NOEXCEPT {
 	return;
 }
 
-ALC_API const ALCchar * ALC_APIENTRY alcGetString( ALCdevice *deviceHandle, ALCenum token ) {
+ALC_API const ALCchar * ALC_APIENTRY alcGetString( ALCdevice *deviceHandle, ALCenum token ) AL_API_NOEXCEPT {
 	return NULL;
 }
 
-AL_API void AL_APIENTRY alDeleteSources( ALsizei n, const ALuint* sources ) { }
+AL_API void AL_APIENTRY alDeleteSources( ALsizei n, const ALuint* sources ) AL_API_NOEXCEPT { }
 
-AL_API ALenum AL_APIENTRY alGetEnumValue( const ALchar* ename ) {
+AL_API ALenum AL_APIENTRY alGetEnumValue( const ALchar* ename ) AL_API_NOEXCEPT {
 	return 0;
 }
 
-AL_API void* AL_APIENTRY alGetProcAddress( const ALchar* fname ) {
+AL_API void* AL_APIENTRY alGetProcAddress( const ALchar* fname ) AL_API_NOEXCEPT {
 	return NULL;
 }
 
 ALC_API ALCcontext * ALC_APIENTRY alcCreateContext( ALCdevice *dev,
-												  const ALCint* attrlist ) {
+												  const ALCint* attrlist ) AL_API_NOEXCEPT {
 	return NULL;
 }
 
-AL_API void AL_APIENTRY alListenerfv( ALenum pname, const ALfloat* param ) { }
+AL_API void AL_APIENTRY alListenerfv( ALenum pname, const ALfloat* param ) AL_API_NOEXCEPT { }
 
-AL_API void AL_APIENTRY alSourceQueueBuffers( ALuint sid, ALsizei numEntries, const ALuint *bids ) { }
+AL_API void AL_APIENTRY alSourceQueueBuffers( ALuint sid, ALsizei numEntries, const ALuint *bids ) AL_API_NOEXCEPT { }
 
-AL_API void AL_APIENTRY alSourcei( ALuint sid, ALenum param, ALint value ) { }
+AL_API void AL_APIENTRY alSourcei( ALuint sid, ALenum param, ALint value ) AL_API_NOEXCEPT { }
 
-AL_API void AL_APIENTRY alListenerf( ALenum pname, ALfloat param ) { }
+AL_API void AL_APIENTRY alListenerf( ALenum pname, ALfloat param ) AL_API_NOEXCEPT { }
 
-ALC_API ALCboolean ALC_APIENTRY alcCloseDevice( ALCdevice *dev ) { return false; }
+ALC_API ALCboolean ALC_APIENTRY alcCloseDevice( ALCdevice *dev ) AL_API_NOEXCEPT { return false; }
 
-AL_API ALboolean AL_APIENTRY alIsBuffer( ALuint buffer ) {
+AL_API ALboolean AL_APIENTRY alIsBuffer( ALuint buffer ) AL_API_NOEXCEPT {
 	return AL_FALSE;
 }
 
 AL_API void AL_APIENTRY alSource3f( ALuint sid, ALenum param,
-								  ALfloat f1, ALfloat f2, ALfloat f3 ) { }
+								  ALfloat f1, ALfloat f2, ALfloat f3 ) AL_API_NOEXCEPT { }
 
-AL_API void AL_APIENTRY alGenSources( ALsizei n, ALuint* sources ) { }
+AL_API void AL_APIENTRY alGenSources( ALsizei n, ALuint* sources ) AL_API_NOEXCEPT { }
 
-AL_API void AL_APIENTRY alSourcef( ALuint sid, ALenum param, ALfloat value ) { }
+AL_API void AL_APIENTRY alSourcef( ALuint sid, ALenum param, ALfloat value ) AL_API_NOEXCEPT { }
 
-AL_API void AL_APIENTRY alSourceUnqueueBuffers( ALuint sid, ALsizei numEntries, ALuint *bids ) { }
+AL_API void AL_APIENTRY alSourceUnqueueBuffers( ALuint sid, ALsizei numEntries, ALuint *bids ) AL_API_NOEXCEPT { }
 
-AL_API void AL_APIENTRY alSourcePlay( ALuint sid ) { }
-AL_API void AL_APIENTRY alSourcePause( ALuint source ) {}
+AL_API void AL_APIENTRY alSourcePlay( ALuint sid ) AL_API_NOEXCEPT { }
+AL_API void AL_APIENTRY alSourcePause( ALuint source ) AL_API_NOEXCEPT {}
 
 } // extern "C"
