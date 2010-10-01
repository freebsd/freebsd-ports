--- src/hamster/widgets/timeinput.py	2010-06-04 20:53:24.000000000 +0400
+++ src/hamster/widgets/timeinput.py	2010-09-26 01:33:38.000000000 +0400
@@ -17,7 +17,7 @@
 # You should have received a copy of the GNU General Public License
 # along with Project Hamster.  If not, see <http://www.gnu.org/licenses/>.
 
-from .hamster.stuff import format_duration
+from hamster.stuff import format_duration
 import gtk
 from gtk import keysyms
 import datetime as dt
