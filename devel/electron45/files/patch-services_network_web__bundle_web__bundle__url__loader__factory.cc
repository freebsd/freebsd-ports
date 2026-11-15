--- services/network/web_bundle/web_bundle_url_loader_factory.cc.orig	2026-11-05 12:23:53 UTC
+++ services/network/web_bundle/web_bundle_url_loader_factory.cc
@@ -577,6 +577,7 @@ void WebBundleURLLoaderFactory::SetBundleStream(
 
 void WebBundleURLLoaderFactory::SetBundleStream(
     mojo::ScopedDataPipeConsumerHandle body) {
+#if !BUILDFLAG(IS_BSD)
   if (HasError())
     return;
   mojo::PendingRemote<web_package::mojom::BundleDataSource> data_source;
@@ -596,6 +597,11 @@ void WebBundleURLLoaderFactory::SetBundleStream(
       /*offset=*/std::nullopt,
       base::BindOnce(&WebBundleURLLoaderFactory::OnMetadataParsed,
                      weak_ptr_factory_.GetWeakPtr()));
+#else
+  // XXX crubit
+  NOTIMPLEMENTED();
+  return;
+#endif
 }
 
 mojo::PendingRemote<mojom::URLLoaderClient>
