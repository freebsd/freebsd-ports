--- src/application.py.orig	2015-04-17 13:26:29 UTC
+++ src/application.py
@@ -11,7 +11,7 @@
 # You should have received a copy of the GNU General Public License
 # along with this program. If not, see <http://www.gnu.org/licenses/>.
 
-from gi.repository import Gtk, Gio, GLib, Gdk, Notify, TotemPlParser
+from gi.repository import Gtk, Gio, GLib, Gdk, Notify
 from locale import getlocale
 
 from lollypop.utils import is_audio, is_gnome
@@ -75,9 +75,6 @@ class Application(Gtk.Application):
         dark = Objects.settings.get_value('dark-ui')
         settings.set_property("gtk-application-prefer-dark-theme", dark)
 
-        self._parser = TotemPlParser.Parser.new()
-        self._parser.connect("entry-parsed", self._on_entry_parsed)
-        self._parser.connect("playlist-ended", self._on_playlist_ended)
         self._parsing = 0
 
         self.add_action(Objects.settings.create_action('shuffle'))
@@ -140,10 +137,7 @@ class Application(Gtk.Application):
     def do_open(self, files, hint, data):
         self._external_files = []
         for f in files:
-            if self._parser.parse(f.get_uri(), False) ==\
-                                           TotemPlParser.ParserResult.SUCCESS:
-                self._parsing += 1
-            elif is_audio(f):
+            if is_audio(f):
                 self._external_files.append(f.get_path())
         if not Objects.window.is_visible():
             self.do_activate()
@@ -185,29 +179,6 @@ class Application(Gtk.Application):
 # PRIVATE             #
 #######################
     """
-        Add playlist entry to external files
-        @param parser as TotemPlParser.Parser
-        @param track uri as str
-        @param metadata as GLib.HastTable
-    """
-    def _on_entry_parsed(self, parser, uri, metadata):
-        # Check if it's really a file uri
-        if uri.startswith('file://'):
-            self._external_files.append(GLib.filename_from_uri(uri)[0])
-        else:
-            self._external_files.append(uri)
-
-    """
-        Load tracks if no parsing running
-        @param parser as TotemPlParser.Parser
-        @param playlist uri as str
-    """
-    def _on_playlist_ended(self, parser, uri):
-        self._parsing -= 1
-        if self._parsing == 0:
-            Objects.window.load_external(self._external_files)
-
-    """
         Hide window
         @param widget as Gtk.Widget
         @param event as Gdk.Event
