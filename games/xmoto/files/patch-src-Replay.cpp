--- src/Replay.cpp.orig	2009-08-21 13:16:38.000000000 +0400
+++ src/Replay.cpp	2009-09-14 01:57:12.000000000 +0400
@@ -156,7 +156,7 @@
     v_replay.writeBuf(pcData, nDataSize);
     
     /* Chunks */
-    v_replay << m_Chunks.size();
+    v_replay << (unsigned int)m_Chunks.size();
     for(unsigned int i=0;i<m_Chunks.size();i++) {
       v_replay << m_Chunks[i]->nNumStates;
       v_replay.writeBuf(m_Chunks[i]->pcChunkData, m_nStateSize * m_Chunks[i]->nNumStates);
