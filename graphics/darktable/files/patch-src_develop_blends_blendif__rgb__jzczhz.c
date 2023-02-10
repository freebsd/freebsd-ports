--- src/develop/blends/blendif_rgb_jzczhz.c.orig	2023-01-26 22:19:33 UTC
+++ src/develop/blends/blendif_rgb_jzczhz.c
@@ -16,15 +16,6 @@
     along with darktable.  If not, see <http://www.gnu.org/licenses/>.
 */
 
-#if defined(__GNUC__)
-#pragma GCC optimize("unroll-loops", "tree-loop-if-convert", "tree-loop-distribution", "no-strict-aliasing",      \
-                     "loop-interchange", "loop-nest-optimize", "tree-loop-im", "unswitch-loops",                  \
-                     "tree-loop-ivcanon", "ira-loop-pressure", "split-ivs-in-unroller", "tree-loop-vectorize",    \
-                     "variable-expansion-in-unroller", "split-loops", "ivopts", "predictive-commoning",           \
-                     "tree-loop-linear", "loop-block", "loop-strip-mine", "finite-math-only", "fp-contract=fast", \
-                     "fast-math", "no-math-errno")
-#endif
-
 #include "common/colorspaces_inline_conversions.h"
 #include "common/imagebuf.h"
 #include "develop/blend.h"
