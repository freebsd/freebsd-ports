--- libsee/value.c.orig	Sat Feb  9 13:54:59 2008
+++ libsee/value.c	Thu Aug 21 13:07:30 2008
@@ -27,7 +27,7 @@
  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  * POSSIBILITY OF SUCH DAMAGE.
  */
-/* $Id: value.c 1370 2008-02-09 12:54:24Z d $ */
+/* $Id: value.c 1383 2008-07-03 13:56:11Z d $ */
 
 #if HAVE_CONFIG_H
 # include <config.h>
@@ -289,14 +289,17 @@
 		} else if (SEE_NUMBER_ISPINF(val)) {
 			SEE_SET_STRING(res, STR(Infinity));
 		} else {
-			char *a, *endstr;
+			char *a0, *a, *endstr;
 			struct SEE_string *s;
 			int sign, k, n, i, exponent;
 			int len;
 
-			a = SEE_dtoa(val->u.number, DTOA_MODE_SHORT_SW, 31, 
+			a0 = SEE_dtoa(val->u.number, DTOA_MODE_SHORT_SW, 31, 
 				&n, &sign, &endstr);
-			k = (int)(endstr - a);
+			k = (int)(endstr - a0);
+			a = SEE_STRING_ALLOCA(interp, char, k);
+			memcpy(a, a0, k);
+			SEE_freedtoa(a0);
 
 			/* Numbers converted to strings are generally
 			 * small and short-lived. */
@@ -359,7 +362,6 @@
 			}
 			SEE_ASSERT(interp, len == s->length);
 			SEE_SET_STRING(res, s);
-			SEE_freedtoa(a);
 		} 
 		break;
 	case SEE_STRING:
