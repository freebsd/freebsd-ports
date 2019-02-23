--- sources/xray_re/xr_packet.h.orig	2018-09-02 12:42:44 UTC
+++ sources/xray_re/xr_packet.h
@@ -180,14 +180,14 @@ inline void xr_ini_packet::w_seq(std::vector<uint16_t>
 }
 
 template<typename T> inline void xr_ini_packet::write(const T& value){
-	int n = xr_snprintf(m_key_buffer, sizeof(m_key_buffer), "%06d", ++m_counter);
+	xr_snprintf(m_key_buffer, sizeof(m_key_buffer), "%06d", ++m_counter);
 	w->write(m_key_buffer, value);
 	w_seek(w_tell() + sizeof(T));
 }
 
 template<typename T> inline void xr_ini_packet::write_number(const T& value){
-	int n = xr_snprintf(m_key_buffer, sizeof(m_key_buffer), "%06d", ++m_counter);
-	n = xr_snprintf(m_temp_buffer, sizeof(m_temp_buffer), "%d", value);
+	xr_snprintf(m_key_buffer, sizeof(m_key_buffer), "%06d", ++m_counter);
+	xr_snprintf(m_temp_buffer, sizeof(m_temp_buffer), "%d", value);
 	w->write(m_key_buffer, m_temp_buffer, false);
 	w_seek(w_tell() + sizeof(T));
 }
