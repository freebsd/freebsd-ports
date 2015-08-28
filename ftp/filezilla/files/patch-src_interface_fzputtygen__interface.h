--- src/interface/fzputtygen_interface.h.orig	2015-08-18 16:02:52 UTC
+++ src/interface/fzputtygen_interface.h
@@ -0,0 +1,40 @@
+#ifndef FILEZILLA_FZPUTTYGEN_INTERFACE_HEADER
+#define FILEZILLA_FZPUTTYGEN_INTERFACE_HEADER
+
+#include <wx/process.h>
+
+class CFZPuttyGenInterface
+{
+public:
+	CFZPuttyGenInterface(wxWindow* parent);
+	virtual ~CFZPuttyGenInterface();
+	bool LoadKeyFile(wxString& keyFile, bool silent, wxString& comment, wxString& data);
+
+	void EndProcess();
+	void DeleteProcess();
+	bool IsProcessCreated();
+	bool IsProcessStarted();
+
+protected:
+	// return -1 on error
+	int NeedsConversion(wxString keyFile, bool silent);
+
+	// return -1 on error
+	int IsKeyFileEncrypted(wxString keyFile, bool silent);
+
+	wxProcess* m_pProcess{};
+	bool m_initialized{};
+	wxWindow* m_parent;
+	
+	enum ReplyCode {
+		success,
+		error,
+		failure
+	};
+
+	bool LoadProcess(bool silent);
+	bool Send(const wxString& cmd);
+	ReplyCode GetReply(wxString& reply);
+};
+
+#endif /* FILEZILLA_FZPUTTYGEN_INTERFACE_HEADER */
