--- setup.py.orig	Fri Mar 30 08:39:28 2007
+++ setup.py	Fri Mar 30 08:39:37 2007
@@ -16,11 +16,11 @@
 # You should have received a copy of the GNU General Public License along with
 # this program; if not, write to the Free Software Foundation, Inc.,
 # 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
+from __future__ import nested_scopes
 """ Generic Setup script, takes package info from __pkginfo__.py file """
 
 __revision__ = '$Id: setup.py,v 1.17 2005/01/05 11:40:41 syt Exp $'
 
-from __future__ import nested_scopes
 import os
 import sys
 import shutil
