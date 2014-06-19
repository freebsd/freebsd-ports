--- include/smack/blob.hpp.orig	2012-12-06 22:30:27.000000000 +0400
+++ include/smack/blob.hpp	2014-06-16 17:12:07.000000000 +0400
@@ -589,7 +589,7 @@
 			if (idx != -1) {
 				m_chunk_idx = idx;
 				fin_t in;
-				m_files[idx]->read_index<fin_t>(in, m_chunks, m_chunks_unsorted, 0);
+				m_files[idx]->template read_index<fin_t>(in, m_chunks, m_chunks_unsorted, 0);
 
 				log(SMACK_LOG_INFO, "%s: read-index: idx: %d, sorted: %zd, unsorted: %zd, num: %zd\n",
 						m_path.c_str(), idx, m_chunks.size(), m_chunks_unsorted.size(), this->num());
