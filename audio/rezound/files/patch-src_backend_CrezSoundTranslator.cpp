--- src/backend/CrezSoundTranslator.cpp.orig	2013-02-10 06:35:01 UTC
+++ src/backend/CrezSoundTranslator.cpp
@@ -43,7 +43,7 @@ CrezSoundTranslator::~CrezSoundTranslator()
 
 // need to include this I use some of the template *methods* for types that are no where else
 // so the explicit instantation at the bottom of CSound.cpp doesn't instantiate everything
-#include <TPoolFile.cpp>
+// #include <TPoolFile.cpp>
 
 struct RFormatInfo1
 {
@@ -63,7 +63,7 @@ struct RFormatInfo1
 	{
 		// unpack the values from r into the data members
 	
-		register unsigned offset=0;
+		unsigned offset=0;
 		
 		memcpy(&version,r+offset,sizeof(version));
 		lethe(&version);
@@ -103,7 +103,7 @@ struct RFormatInfo2
 	{
 		// unpack the values from r into the data members
 	
-		register unsigned offset=0;
+		unsigned offset=0;
 		
 		memcpy(&version,r+offset,sizeof(version));
 		lethe(&version);
@@ -149,7 +149,7 @@ struct RFormatInfo3
 	{
 		// pack the values of the data members into r
 		
-		register unsigned offset=0;
+		unsigned offset=0;
 
 		uint32_t tVersion=hetle(version);
 		memcpy(r+offset,&tVersion,sizeof(version));
@@ -175,7 +175,7 @@ struct RFormatInfo3
 	{
 		// unpack the values from r into the data members
 
-		register unsigned offset=0;
+		unsigned offset=0;
 
 		memcpy(&version,r+offset,sizeof(version));
 		lethe(&version);
@@ -221,7 +221,7 @@ typedef TPoolAccesser<RFormatInfo3::PackedChunk,CSound
 // loads data from poolfile as type src_t and writes into dest as sample_t
 template<typename src_t> inline bool CrezSoundTranslator::load_samples_from_X_to_native(unsigned i,CSound::PoolFile_t &loadFromFile,CSound *sound,const TStaticPoolAccesser<src_t,CSound::PoolFile_t> &src,const sample_pos_t size,CStatusBar &statusBar,Endians endian)
 {
-	const register sample_pos_t chunkSize=size/100;
+	const sample_pos_t chunkSize=size/100;
 	CSound::CInternalRezPoolAccesser dest=sound->getAudioInternal(i);
 	sample_pos_t pos=0;
 	
@@ -276,7 +276,7 @@ inline bool CrezSoundTranslator::load_samples__sample_
 {
 	CSound::CInternalRezPoolAccesser dest=sound->getAudioInternal(i);
 
-	const register sample_pos_t chunkSize=size/100;
+	const sample_pos_t chunkSize=size/100;
 
 	for(unsigned int t=0;t<100 && chunkSize>0;t++)
 	{
