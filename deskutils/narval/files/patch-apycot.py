--- apycot.py.orig	2007-11-05 12:48:48.000000000 +0100
+++ apycot.py	2007-11-05 12:49:18.000000000 +0100
@@ -17,6 +17,8 @@
 # You should have received a copy of the GNU Lesser General Public
 # License along with this library; if not, write to the Free Software
 # Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
+from __future__ import generators
+
 """Apycot_ extenstions for narval acceptance tests
 
 .. _Apycot: http://www.logilab.org/projects/apycot
@@ -44,8 +46,6 @@
 __revision__ = '$Id: autotest.py,v 1.2 2002/08/14 11:47:37 syt Exp $'
 __docformat__ = "restructuredtext en"
 
-from __future__ import generators
-
 import sys
 import re
 import traceback
