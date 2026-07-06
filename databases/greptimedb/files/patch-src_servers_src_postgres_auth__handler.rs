-- Fix build with recent Rust nightly where std::sync::Exclusive was renamed to std::sync::SyncView.
-- This patch ensures compatibility with the latest Rust compiler.

--- src/servers/src/postgres/auth_handler.rs.orig	2026-05-14 04:45:39 UTC
+++ src/servers/src/postgres/auth_handler.rs
@@ -13,7 +13,7 @@ use std::fmt::Debug;
 // limitations under the License.
 
 use std::fmt::Debug;
-use std::sync::Exclusive;
+use std::sync::SyncView;
 
 use ::auth::{Identity, Password, UserInfoRef, UserProviderRef, userinfo_by_name};
 use async_trait::async_trait;
@@ -160,7 +160,7 @@ impl StartupHandler for PostgresServerHandlerInner {
                 auth::save_startup_parameters_to_metadata(client, startup);
 
                 // check if db is valid
-                match resolve_db_info(Exclusive::new(client), self.query_handler.clone()).await? {
+                match resolve_db_info(SyncView::new(client), self.query_handler.clone()).await? {
                     DbResolution::Resolved(catalog, schema) => {
                         let metadata = client.metadata_mut();
                         let _ = metadata.insert(super::METADATA_CATALOG.to_owned(), catalog);
@@ -255,7 +255,7 @@ async fn resolve_db_info<C>(
 
 /// A function extracted to resolve lifetime and readability issues:
 async fn resolve_db_info<C>(
-    client: Exclusive<&mut C>,
+    client: SyncView<&mut C>,
     query_handler: ServerSqlQueryHandlerRef,
 ) -> PgWireResult<DbResolution>
 where
