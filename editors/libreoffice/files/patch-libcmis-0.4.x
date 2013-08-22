--- ucb/source/ucp/cmis/auth_provider.hxx.orig	2013-08-13 16:11:48.000000000 -0400
+++ ucb/source/ucp/cmis/auth_provider.hxx	2013-08-16 18:32:50.000000000 -0400
@@ -28,7 +28,7 @@
 #ifndef AUTH_PROVIDER_HXX
 #define AUTH_PROVIDER_HXX
 
-#include <libcmis/session.hxx>
+#include <libcmis/libcmis.hxx>
 
 #include <com/sun/star/ucb/XCommandEnvironment.hpp>
 
--- ucb/source/ucp/cmis/cmis_content.cxx.orig	2013-08-13 16:11:48.000000000 -0400
+++ ucb/source/ucp/cmis/cmis_content.cxx	2013-08-16 18:32:50.000000000 -0400
@@ -51,8 +51,6 @@
 #include <com/sun/star/ucb/XCommandInfo.hpp>
 #include <com/sun/star/ucb/XDynamicResultSet.hpp>
 
-#include <libcmis/document.hxx>
-
 #include <comphelper/processfactory.hxx>
 #include <ucbhelper/cancelcommandexecution.hxx>
 #include <ucbhelper/content.hxx>
--- ucb/source/ucp/cmis/cmis_content.hxx.orig	2013-08-13 16:11:48.000000000 -0400
+++ ucb/source/ucp/cmis/cmis_content.hxx	2013-08-16 18:32:50.000000000 -0400
@@ -40,7 +40,7 @@
 #include <com/sun/star/ucb/TransferInfo.hpp>
 #include <com/sun/star/ucb/XContentCreator.hpp>
 #include <ucbhelper/contenthelper.hxx>
-#include <libcmis/session-factory.hxx>
+#include <libcmis/libcmis.hxx>
 
 #include <list>
 
--- ucb/source/ucp/cmis/cmis_provider.hxx.orig	2013-08-13 16:11:48.000000000 -0400
+++ ucb/source/ucp/cmis/cmis_provider.hxx	2013-08-16 18:32:50.000000000 -0400
@@ -31,7 +31,7 @@
 
 #include <com/sun/star/beans/Property.hpp>
 #include <ucbhelper/providerhelper.hxx>
-#include <libcmis/session.hxx>
+#include <libcmis/libcmis.hxx>
 
 namespace cmis
 {
--- ucb/source/ucp/cmis/cmis_repo_content.cxx.orig	2013-08-13 16:11:48.000000000 -0400
+++ ucb/source/ucp/cmis/cmis_repo_content.cxx	2013-08-16 18:32:50.000000000 -0400
@@ -59,7 +59,7 @@
 {
     RepoContent::RepoContent( const uno::Reference< uno::XComponentContext >& rxContext,
         ContentProvider *pProvider, const uno::Reference< ucb::XContentIdentifier >& Identifier,
-        list< libcmis::RepositoryPtr > aRepos )
+        vector< libcmis::RepositoryPtr > aRepos )
             throw ( ucb::ContentCreationException )
         : ContentImplHelper( rxContext, pProvider, Identifier ),
         m_pProvider( pProvider ),
@@ -188,7 +188,7 @@
 
         if ( !m_sRepositoryId.isEmpty() )
         {
-            for ( list< libcmis::RepositoryPtr >::iterator it = m_aRepositories.begin( );
+            for ( vector< libcmis::RepositoryPtr >::iterator it = m_aRepositories.begin( );
                     it != m_aRepositories.end( ) && NULL == repo.get( ); ++it )
             {
                 if ( STD_TO_OUSTR( ( *it )->getId( ) ) == m_sRepositoryId )
@@ -368,7 +368,7 @@
 
         if ( m_sRepositoryId.isEmpty( ) )
         {
-            for ( list< libcmis::RepositoryPtr >::iterator it = m_aRepositories.begin( );
+            for ( vector< libcmis::RepositoryPtr >::iterator it = m_aRepositories.begin( );
                     it != m_aRepositories.end(); ++it )
             {
                 URL aUrl( m_aURL );
--- ucb/source/ucp/cmis/cmis_repo_content.hxx.orig	2013-08-13 16:11:48.000000000 -0400
+++ ucb/source/ucp/cmis/cmis_repo_content.hxx	2013-08-16 18:32:50.000000000 -0400
@@ -39,8 +39,9 @@
 #include <com/sun/star/ucb/TransferInfo.hpp>
 #include <com/sun/star/ucb/XContentCreator.hpp>
 #include <ucbhelper/contenthelper.hxx>
-#include <libcmis/repository.hxx>
+#include <libcmis/libcmis.hxx>
 
+#include <vector>
 #include <list>
 
 namespace com { namespace sun { namespace star {
@@ -71,7 +72,7 @@
     URL                    m_aURL;
     rtl::OUString          m_sRepositoryId;
 
-    std::list< libcmis::RepositoryPtr > m_aRepositories;
+    std::vector< libcmis::RepositoryPtr > m_aRepositories;
 
 private:
 
@@ -95,7 +96,7 @@
     RepoContent( const com::sun::star::uno::Reference<
         com::sun::star::uno::XComponentContext >& rxContext, ContentProvider *pProvider,
         const com::sun::star::uno::Reference< com::sun::star::ucb::XContentIdentifier >& Identifier,
-        std::list< libcmis::RepositoryPtr > aRepos = std::list< libcmis::RepositoryPtr > ( ) )
+        std::vector< libcmis::RepositoryPtr > aRepos = std::vector< libcmis::RepositoryPtr > ( ) )
             throw ( com::sun::star::ucb::ContentCreationException );
 
     virtual ~RepoContent();
--- ucb/source/ucp/cmis/cmis_url.cxx.orig	2013-08-13 16:11:48.000000000 -0400
+++ ucb/source/ucp/cmis/cmis_url.cxx	2013-08-16 18:32:50.000000000 -0400
@@ -26,7 +26,7 @@
  * instead of those above.
  */
 
-#include <libcmis/session-factory.hxx>
+#include <libcmis/libcmis.hxx>
 
 #include <rtl/uri.hxx>
 
