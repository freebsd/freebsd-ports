--- src/iop/channelmixerrgb.c.orig	2024-07-27 09:15:05 UTC
+++ src/iop/channelmixerrgb.c
@@ -16,23 +16,6 @@
   along with darktable.  If not, see <http://www.gnu.org/licenses/>.
 */
 
-/** Note :
- * we use finite-math-only and fast-math because divisions by zero are manually avoided in the code
- * fp-contract=fast enables hardware-accelerated Fused Multiply-Add
- * the rest is loop reorganization and vectorization optimization
- **/
-#if defined(__GNUC__)
-#pragma GCC optimize ("unroll-loops", "tree-loop-if-convert", \
-                      "tree-loop-distribution", "no-strict-aliasing", \
-                      "loop-interchange", "loop-nest-optimize", "tree-loop-im", \
-                      "unswitch-loops", "tree-loop-ivcanon", "ira-loop-pressure", \
-                      "split-ivs-in-unroller", "variable-expansion-in-unroller", \
-                      "split-loops", "ivopts", "predictive-commoning",\
-                      "tree-loop-linear", "loop-block", "loop-strip-mine", \
-                      "finite-math-only", "fp-contract=fast", "fast-math", \
-                      "tree-vectorize", "no-math-errno")
-#endif
-
 // #define AI_ACTIVATED
 /* AI feature not good enough so disabled for now
    If enabled there must be $DESCRIPTION: entries in illuminants.h for bauhaus
