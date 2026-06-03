--- scripts/sokSettings.py.orig	2025-07-03 16:13:44 UTC
+++ scripts/sokSettings.py
@@ -16,7 +16,7 @@
 # You should have received a copy of the GNU General Public License
 # along with this program. If not, see <http://www.gnu.org/licenses/>.
 
-PYTHON_EXECUTABLE = "python3"
+PYTHON_EXECUTABLE = "%%PYTHON_CMD%%"
 
 from gi.repository import GLib
 
