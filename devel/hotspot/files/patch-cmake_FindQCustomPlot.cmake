--- cmake/FindQCustomPlot.cmake.orig	2024-04-25 19:14:17 UTC
+++ cmake/FindQCustomPlot.cmake
@@ -30,7 +30,7 @@
 # (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 # THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
-find_library(QCustomPlot_LIBRARY NAMES qcustomplot-qt${QT_MAJOR_VERSION} qcustomplot)
+find_library(QCustomPlot_LIBRARY NAMES QCustomPlot-qt${QT_MAJOR_VERSION})
 set(QCustomPlot_LIBRARIES "${QCustomPlot_LIBRARY}")
 
 find_path(QCustomPlot_INCLUDE_DIR NAMES qcustomplot.h)
