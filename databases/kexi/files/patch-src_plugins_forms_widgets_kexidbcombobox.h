Fix the build with LLVM < 4.0 (https://bugs.llvm.org//show_bug.cgi?id=26297).

/wrkdirs/usr/ports/databases/kexi/work/kexi-3.0.0/src/plugins/forms/widgets/kexidbcombobox.h:47:33: error: return type of virtual function 'column' is not covariant with
      the return type of the function it overrides ('KDbTableViewColumn' is incomplete)
    virtual KDbTableViewColumn *column() const;
                                ^
/usr/local/include/KDb3/KDbTableViewData.h:36:7: note: forward declaration of 'KDbTableViewColumn'
class KDbTableViewColumn;
      ^
--- src/plugins/forms/widgets/kexidbcombobox.h.orig	2017-06-11 15:09:35 UTC
+++ src/plugins/forms/widgets/kexidbcombobox.h
@@ -24,6 +24,8 @@
 #include "kexidbautofield.h"
 #include <widget/tableview/kexicomboboxbase.h>

+#include <KDb3/KDbTableViewColumn.h>
+
 //! @short Combo box widget for Kexi forms
 /*! This widget is implemented on top of KexiDBAutoField,
  so as it uses KexiDBAutoField's ability of embedding subwidgets,
