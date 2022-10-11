--- eeschema/sim/sim_plot_frame.cpp.orig	2022-09-14 16:35:24 UTC
+++ eeschema/sim/sim_plot_frame.cpp
@@ -167,15 +167,15 @@ SIM_PLOT_FRAME::SIM_PLOT_FRAME( KIWAY* aKiway, wxWindo
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
-    m_toolSettings = m_toolBar->AddTool( wxID_ANY, _( "Sim Parameters" ),
+    m_toolSettings = m_toolBar->AddTool( wxID_ANY, wxEmptyString,
             KiBitmap( BITMAPS::config ), _( "Simulation parameters and settings" ), wxITEM_NORMAL );
 
     // Start all toolbar buttons except settings as disabled
