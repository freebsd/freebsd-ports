--- ./Automoc4Config.cmake.orig	2012-05-28 10:08:18.449122610 +0200
+++ ./Automoc4Config.cmake	2012-05-28 10:09:14.719218317 +0200
@@ -49,7 +49,8 @@
 #     THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
 
-get_filename_component(_AUTOMOC4_CURRENT_DIR  "${CMAKE_CURRENT_LIST_FILE}" PATH)
+get_filename_component(_AUTOMOC4_CURRENT_DIR  "${CMAKE_CURRENT_LIST_FILE}" REALPATH)
+get_filename_component(_AUTOMOC4_CURRENT_DIR  "${_AUTOMOC4_CURRENT_DIR}" PATH)
 
 # set the automoc version number
 include(${_AUTOMOC4_CURRENT_DIR}/Automoc4Version.cmake)
