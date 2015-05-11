--- src/wefax/wefax.cxx.orig	2015-04-22 15:17:06 UTC
+++ src/wefax/wefax.cxx
@@ -556,7 +556,7 @@ private:
 			= wf->powerDensity(m_carrier - 2 * m_apt_start_freq, bandwidth_apt_start)
 			+ wf->powerDensity(m_carrier -     m_apt_start_freq, bandwidth_apt_start)
 			+ wf->powerDensity(m_carrier                       , bandwidth_apt_start)
-			+ wf->powerDensity(m_carrier +     m_apt_start_freq, bandwidth_apt_start);
+			+ wf->powerDensity(m_carrier +     m_apt_start_freq, bandwidth_apt_start)
 			+ wf->powerDensity(m_carrier + 2 * m_apt_start_freq, bandwidth_apt_start);
 
        		return decayavg( avg_pwr, pwr, 10 );
