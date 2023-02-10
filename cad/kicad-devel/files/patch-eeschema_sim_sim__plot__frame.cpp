--- eeschema/sim/sim_plot_frame.cpp.orig	2023-01-06 17:32:00.707624000 +0100
+++ eeschema/sim/sim_plot_frame.cpp	2023-01-06 17:35:04.237427000 +0100
@@ -156,15 +156,15 @@
     Bind( EVT_SIM_CURSOR_UPDATE, &SIM_PLOT_FRAME::onCursorUpdate, this );
 
     // Toolbar buttons
-    m_toolSimulate = m_toolBar->AddTool( ID_SIM_RUN, _( "Run/Stop Simulation" ),
+    m_toolSimulate = m_toolBar->AddTool( ID_SIM_RUN, wxEmptyString,
             KiBitmap( BITMAPS::sim_run ), _( "Run Simulation" ), wxITEM_NORMAL );
-    m_toolAddSignals = m_toolBar->AddTool( ID_SIM_ADD_SIGNALS, _( "Add Signals" ),
+    m_toolAddSignals = m_toolBar->AddTool( ID_SIM_ADD_SIGNALS, wxEmptyString,
             KiBitmap( BITMAPS::sim_add_signal ), _( "Add signals to plot" ), wxITEM_NORMAL );
-    m_toolProbe = m_toolBar->AddTool( ID_SIM_PROBE,  _( "Probe" ),
+    m_toolProbe = m_toolBar->AddTool( ID_SIM_PROBE,  wxEmptyString,
             KiBitmap( BITMAPS::sim_probe ), _( "Probe signals on the schematic" ), wxITEM_NORMAL );
-    m_toolTune = m_toolBar->AddTool( ID_SIM_TUNE, _( "Tune" ),
+    m_toolTune = m_toolBar->AddTool( ID_SIM_TUNE, wxEmptyString,
             KiBitmap( BITMAPS::sim_tune ), _( "Tune component values" ), wxITEM_NORMAL );
-    m_toolSettings = m_toolBar->AddTool( wxID_ANY, _( "Sim Command" ),
+    m_toolSettings = m_toolBar->AddTool( wxID_ANY, wxEmptyString,
             KiBitmap( BITMAPS::config ), _( "Simulation command and settings" ), wxITEM_NORMAL );
 
     // Start all toolbar buttons except settings as disabled
