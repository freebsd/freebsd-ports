--- ../toolkit/inc/toolkit/helper/IComboListBoxHelper.hxx.orig	Wed May  7 11:05:11 2003
+++ ../toolkit/inc/toolkit/helper/IComboListBoxHelper.hxx	Wed Jun  4 00:07:03 2003
@@ -103,10 +103,10 @@
 		virtual void			SetNoSelection() = 0;
 		virtual USHORT			GetSelectEntryPos( USHORT nSelIndex = 0 ) const = 0;
 		virtual BOOL            IsInDropDown() const = 0;
-        virtual Rectangle       GetEntryCharacterBounds( const sal_Int32 _nEntryPos, const sal_Int32 _nCharacterIndex ) const;
-        virtual long            GetIndexForPoint( const Point& rPoint ) const;
-        virtual ::com::sun::star::uno::Reference< ::com::sun::star::datatransfer::clipboard::XClipboard >
-                                GetClipboard();
+		virtual Rectangle       GetEntryCharacterBounds( const sal_Int32 _nEntryPos, const sal_Int32 _nCharacterIndex ) const = 0;
+		virtual long            GetIndexForPoint( const Point& rPoint ) const = 0;
+		virtual ::com::sun::star::uno::Reference< ::com::sun::star::datatransfer::clipboard::XClipboard >
+		GetClipboard() = 0;
 	};
 }
 #endif // TOOLKIT_HELPER_COMBOLISTBOXHELPER_HXX
