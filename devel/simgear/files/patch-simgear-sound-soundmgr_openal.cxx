Backport commits b9deeb and a97c14 from upstream

--- simgear/sound/soundmgr_openal.cxx.orig	2016-10-21 11:49:23.424814177 +0000
+++ simgear/sound/soundmgr_openal.cxx	2016-10-21 11:49:47.078812408 +0000
@@ -757,14 +757,14 @@
 bool SGSoundMgr::is_sample_stopped(SGSoundSample *sample)
 {
 #ifdef ENABLE_SOUND
-    assert(sample->is_valid_source());
-    unsigned int source = sample->get_source();
-    int result;
-    alGetSourcei( source, AL_SOURCE_STATE, &result );
-    return (result == AL_STOPPED);
-#else
-    return true;
+    if ( sample->is_valid_source() ) {
+        ALint source = sample->get_source();
+        ALint result;
+        alGetSourcei( source, AL_SOURCE_STATE, &result );
+        return (result == AL_STOPPED);
+    }
 #endif
+    return true;
 }
 
 void SGSoundMgr::update_sample_config( SGSoundSample *sample, SGVec3d& position, SGVec3f& orientation, SGVec3f& velocity )
