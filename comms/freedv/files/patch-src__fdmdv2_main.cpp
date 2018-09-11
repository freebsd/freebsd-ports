--- src/fdmdv2_main.cpp.orig	2018-05-29 05:38:34 UTC
+++ src/fdmdv2_main.cpp
@@ -1198,10 +1198,12 @@ void MainFrame::OnTimer(wxTimerEvent &ev
         sprintf(ber, "BER: %4.3f", b); wxString ber_string(ber); m_textBER->SetLabel(ber_string);
         sprintf(resyncs, "Resyncs: %d", g_resyncs); wxString resyncs_string(resyncs); m_textResyncs->SetLabel(resyncs_string);
 
+/*
         sprintf(freqoffset, "FrqOff: %3.1f", g_stats.foff);
         wxString freqoffset_string(freqoffset); m_textFreqOffset->SetLabel(freqoffset_string);
         sprintf(syncmetric, "Sync: %3.2f", g_stats.sync_metric);
         wxString syncmetric_string(syncmetric); m_textSyncMetric->SetLabel(syncmetric_string);
+*/
         
         if (g_State) {
 
