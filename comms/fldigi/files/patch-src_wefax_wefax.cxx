--- src/wefax/wefax.cxx.orig	2013-11-18 09:29:13.581496108 -0500
+++ src/wefax/wefax.cxx	2013-11-18 09:38:30.354457373 -0500
@@ -556,7 +556,7 @@
 			= wf->powerDensity(m_carrier - 2 * m_apt_start_freq, bandwidth_apt_start)
 			+ wf->powerDensity(m_carrier -     m_apt_start_freq, bandwidth_apt_start)
 			+ wf->powerDensity(m_carrier                       , bandwidth_apt_start)
-			+ wf->powerDensity(m_carrier +     m_apt_start_freq, bandwidth_apt_start);
+			+ wf->powerDensity(m_carrier +     m_apt_start_freq, bandwidth_apt_start)
 			+ wf->powerDensity(m_carrier + 2 * m_apt_start_freq, bandwidth_apt_start);
 
        		return decayavg( avg_pwr, pwr, 10 );
