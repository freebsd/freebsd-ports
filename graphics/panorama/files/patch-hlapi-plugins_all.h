--- hlpai/plugins_all.h.orig	Thu Nov 21 01:54:16 2002
+++ hlapi/plugins_all.h	Mon Jan 31 18:34:32 2005
@@ -16,6 +16,7 @@
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
 
+#if ( STATIC_LINK == 1 )
 #include "plugins/atm_object/atm_const/atm_const.h"
 #include "plugins/bsdf/cook_torrance/bsdf_cook_torrance.h"
 #include "plugins/bsdf/lambertian/bsdf_lambertian.h"
@@ -59,12 +60,13 @@
 #include "plugins/object_filter/cartoon/of_cartoon.h"
 #include "plugins/object_filter/convert_to_grey/of_convert_to_grey.h"
 #include "plugins/renderer/raytracer/raytracer.h"
+#endif /* STATIC_LINK == 1 */
 
-#if       defined(USE_EXPERIMENTAL)
+#if ( USE_EXPERIMENTAL == 1 )
 #include "plugins/object/abvh/abvh.h"
 #include "plugins/object/height_field/height_field.h"
 #include "plugins/object/lwo/lwo.h"
 #include "plugins/object/polyhedron/polyhedron.h"
 #include "plugins/object/subdiv/subdiv.h"
 #include "plugins/renderer/zbuffer/zbuffer.h"
-#endif /* defined(USE_EXPERIMENTAL) */
+#endif /* USE_EXPERIMENTAL == 1 */
