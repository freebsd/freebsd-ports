--- book.h.orig	2008-08-16 23:28:06.000000000 -0400
+++ book.h	2008-08-16 23:29:07.000000000 -0400
@@ -27,6 +27,7 @@
   virtual int GetSelection() const { return m_selected;};
   virtual wxSize CalcSizeFromPage(const wxSize& sizePage) const;
 
+  virtual int ChangeSelection(size_t n);
   virtual int SetSelection(size_t n);
 
   // the same as AddPage(), but adds the page at the specified position
