--- libs/indibase/property/indipropertybasic.cpp.orig	2022-05-21 13:52:23 UTC
+++ libs/indibase/property/indipropertybasic.cpp
@@ -16,6 +16,7 @@
     Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */
 
+#include <cassert>
 #include "indipropertybasic.h"
 #include "indipropertybasic_p.h"
 
@@ -342,9 +343,10 @@ const WidgetView<T> *PropertyBasic<T>::at(size_t index
 }
 
 template <typename T>
-WidgetView<T> &PropertyBasic<T>::operator[](size_t index) const
+WidgetView<T> &PropertyBasic<T>::operator[](ssize_t index) const
 {
     D_PTR(const PropertyBasic);
+    assert(index >= 0);
     return *d->property.at(index);
 }
 
