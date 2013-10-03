--- pire/stub/saveload.h.orig	2010-11-16 23:42:09.000000000 +0000
+++ pire/stub/saveload.h
@@ -52,7 +52,7 @@ namespace Pire {
 				if (!Traits::eq_int_type(ret, Traits::eof())) {
 					m_ch = (Char) ret;
 					m_read += sizeof(Char);
-					setg(&m_ch, &m_ch, &m_ch+1);
+					this->setg(&m_ch, &m_ch, &m_ch+1);
 				}
 				return ret;
 			}
@@ -117,7 +117,7 @@ namespace Pire {
 			BasicAlignedOutput(std::basic_ostream<Char, Traits>* backend)
 				: m_streambuf(backend->rdbuf())
 			{
-				rdbuf(&m_streambuf);
+				this->rdbuf(&m_streambuf);
 			}
 
 			void Align(size_t divisor = sizeof(void*))
