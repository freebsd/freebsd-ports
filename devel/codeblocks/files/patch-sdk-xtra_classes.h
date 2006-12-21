--- sdk/xtra_classes.h.orig	Wed Dec 20 23:59:57 2006
+++ sdk/xtra_classes.h	Thu Dec 21 00:00:55 2006
@@ -18,8 +18,8 @@
 class wxSplitPanel : public wxPanel
 {
 public:
-    wxSplitPanel::wxSplitPanel() { /*nothing to init, really */ }
-    wxSplitPanel::wxSplitPanel(wxWindow* parent, wxWindowID id = -1,
+    wxSplitPanel() { /*nothing to init, really */ }
+    wxSplitPanel(wxWindow* parent, wxWindowID id = -1,
                                const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
                                long style = wxTAB_TRAVERSAL, const wxString& name = _T("splitpanel"),const wxString configname = wxEmptyString,int defaultsashposition = 150)
     {
@@ -33,9 +33,9 @@
       * If only one is found, the panel is not split.
       *
       */
-    void wxSplitPanel::RefreshSplitter(int idtop,int idbottom);
+    void RefreshSplitter(int idtop,int idbottom);
 
-    virtual wxSplitPanel::~wxSplitPanel();
+    virtual ~wxSplitPanel();
     wxSplitterWindow* GetSplitter() { return (this) ? m_splitter : 0L; }
     void SetConfigEntryForSplitter(const wxString& splitterconfig){ m_SplitterConfig = splitterconfig; }
 protected:
