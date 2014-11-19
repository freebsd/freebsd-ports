commit 3eef0383f98f8a5e99a07b5998ca035055a1db31
Author: Raphael Kubo da Costa <rakuco@FreeBSD.org>
Date:   Mon Oct 20 23:28:06 2014 +0300

    kimpanel: Include <locale.h> for LC_CTYPE.
    
    Required after 80e34a0cb61aafb925fe38fec5532fa0f28486e9 ("complete ibus
    1.5 port") -- at least on FreeBSD locale.h isn't included indirectly.
    
    CCMAIL: wengxt@gmail.com

--- applets/kimpanel/backend/ibus/ibus15/panel.cpp
+++ applets/kimpanel/backend/ibus/ibus15/panel.cpp
@@ -19,6 +19,7 @@
  *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */
 
+#include <locale.h>
 #include <stdlib.h>
 #include <string.h>
 #include <ibus.h>
