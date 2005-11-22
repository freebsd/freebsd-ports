--- TrustedQSL-1.11/qsodatadialog.cpp.orig	Mon Nov 21 21:27:29 2005
+++ TrustedQSL-1.11/qsodatadialog.cpp	Mon Nov 21 21:34:00 2005
@@ -302,13 +302,13 @@
 		sizer = new wxBoxSizer(wxHORIZONTAL);
 		_recbottom_ctrl = new wxBitmapButton(this, QD_RECBOTTOM, wxBitmap(bottom), wxDefaultPosition, wxSize(18, TEXT_HEIGHT)),
 		sizer->Add(_recbottom_ctrl, 0, wxTOP|wxBOTTOM, 5);
-		_recdown_ctrl = new wxBitmapButton(this, QD_RECDOWN, wxBitmap(left), wxDefaultPosition, wxSize(18, TEXT_HEIGHT));
+		_recdown_ctrl = new wxBitmapButton(this, QD_RECDOWN, wxBitmap(left_i), wxDefaultPosition, wxSize(18, TEXT_HEIGHT));
 		sizer->Add(_recdown_ctrl, 0, wxTOP|wxBOTTOM, 5);
 		_recno_ctrl = new wxTextCtrl(this, QD_RECNO, wxT("1"), wxDefaultPosition,
 			wxSize(4*TEXT_WIDTH,TEXT_HEIGHT));
 		_recno_ctrl->Enable(FALSE);
 		sizer->Add(_recno_ctrl, 0, wxALL, 5);
-		_recup_ctrl = new wxBitmapButton(this, QD_RECUP, wxBitmap(right), wxDefaultPosition, wxSize(18, TEXT_HEIGHT));
+		_recup_ctrl = new wxBitmapButton(this, QD_RECUP, wxBitmap(right_i), wxDefaultPosition, wxSize(18, TEXT_HEIGHT));
 		sizer->Add(_recup_ctrl, 0, wxTOP|wxBOTTOM, 5);
 		_rectop_ctrl = new wxBitmapButton(this, QD_RECTOP, wxBitmap(top), wxDefaultPosition, wxSize(18, TEXT_HEIGHT)),
 		sizer->Add(_rectop_ctrl, 0, wxTOP|wxBOTTOM, 5);
