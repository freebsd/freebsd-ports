Add visibility to C++ exceptions to prevent crashes with applications
using libkcddb.

PR:	211630

--- include/musicbrainz5/HTTPFetch.h.orig	2015-07-06 20:45:19 UTC
+++ include/musicbrainz5/HTTPFetch.h
@@ -29,11 +29,23 @@
 #include <string>
 #include <vector>
 
+// Visibility patch derived from https://gcc.gnu.org/wiki/Visibility ,
+// extended for clang support.
+#if (__clang__) || (__GNUC__ >= 4)
+	#define DLL_PUBLIC __attribute__ ((visibility ("default")))
+	#define DLL_LOCAL  __attribute__ ((visibility ("hidden")))
+#else
+	#define DLL_PUBLIC
+	#define DLL_LOCAL
+#endif
+
+
+
 namespace MusicBrainz5
 {
 	class CHTTPFetchPrivate;
 
-	class CExceptionBase: public std::exception
+	class DLL_PUBLIC CExceptionBase: public std::exception
 	{
 	public:
 		CExceptionBase(const std::string& ErrorMessage, const std::string& Exception)
@@ -60,7 +72,7 @@ namespace MusicBrainz5
 	 * Exception thrown when an error occurs connecting to web service
 	 */
 
-	class CConnectionError: public CExceptionBase
+	class DLL_PUBLIC CConnectionError: public CExceptionBase
 	{
 	public:
 			CConnectionError(const std::string& ErrorMessage)
@@ -73,7 +85,7 @@ namespace MusicBrainz5
 	 * Exception thrown when a connection to the web service times out
 	 */
 
-	class CTimeoutError: public CExceptionBase
+	class DLL_PUBLIC CTimeoutError: public CExceptionBase
 	{
 	public:
 			CTimeoutError(const std::string& ErrorMessage)
@@ -86,7 +98,7 @@ namespace MusicBrainz5
 	 * Exception thrown when an authentication error occurs
 	 */
 
-	class CAuthenticationError: public CExceptionBase
+	class DLL_PUBLIC CAuthenticationError: public CExceptionBase
 	{
 	public:
 			CAuthenticationError(const std::string& ErrorMessage)
@@ -99,7 +111,7 @@ namespace MusicBrainz5
 	 * Exception thrown when an error occurs fetching data
 	 */
 
-	class CFetchError: public CExceptionBase
+	class DLL_PUBLIC CFetchError: public CExceptionBase
 	{
 	public:
 			CFetchError(const std::string& ErrorMessage)
@@ -112,7 +124,7 @@ namespace MusicBrainz5
 	 * Exception thrown when an invalid request is made
 	 */
 
-	class CRequestError: public CExceptionBase
+	class DLL_PUBLIC CRequestError: public CExceptionBase
 	{
 	public:
 			CRequestError(const std::string& ErrorMessage)
@@ -125,7 +137,7 @@ namespace MusicBrainz5
 	 * Exception thrown when the requested resource is not found
 	 */
 
-	class CResourceNotFoundError: public CExceptionBase
+	class DLL_PUBLIC CResourceNotFoundError: public CExceptionBase
 	{
 	public:
 			CResourceNotFoundError(const std::string& ErrorMessage)
