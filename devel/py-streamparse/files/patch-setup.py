--- setup.py.orig	2021-10-04 08:45:30 UTC
+++ setup.py
@@ -14,6 +14,7 @@ WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either e
 See the License for the specific language governing permissions and
 limitations under the License.
 """
+import codecs
 import re
 
 from setuptools import setup, find_packages
@@ -28,7 +29,7 @@ def get_version():
 
 def readme():
     """ Returns README.rst contents as str """
-    with open("README.rst") as f:
+    with codecs.open('README.rst', 'r', encoding='utf8') as f:
         return f.read()
 
 
