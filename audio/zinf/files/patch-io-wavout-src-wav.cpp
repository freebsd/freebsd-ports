--- io/wavout/src/wav.cpp.orig	Tue Mar 18 03:53:30 2003
+++ io/wavout/src/wav.cpp	Sun Nov  9 12:54:05 2003
@@ -101,7 +101,7 @@
 	if (m_FP == NULL) return;
 
 #if !SMALL_ENDIAN
-	m_WH.Length = SWAB32(DataWritten + sizeof(WaveHeader) - 4);
+	m_WH.Length = SWAB32(SWAB32(m_WH.DataLength) + sizeof(WaveHeader) - 4);
 #else
 	m_WH.Length = m_WH.DataLength + sizeof(WaveHeader) - 4;
 #endif
@@ -117,8 +117,7 @@
 DWORD WaveWriter::Write(const char *data, DWORD data_size)
 {
 #if !SMALL_ENDIAN
-	DataWritten+=data_size;
-	m_WH.DataLength=SWAB32(DataWritten);
+	m_WH.DataLength=SWAB32(SWAB32(m_WH.DataLength) + data_size);
 #else
 	m_WH.DataLength+=data_size;
 #endif
