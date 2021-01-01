--- content/browser/storage_partition_impl.cc.orig	2019-04-08 08:32:54 UTC
+++ content/browser/storage_partition_impl.cc
@@ -768,7 +768,7 @@ net::URLRequestContextGetter* StoragePartitionImpl::Ge
   // TODO(jam): enable for all, still used on WebView.
   // See copy of this ifdef in:
   //   StoragePartitionImplMap::Get
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   if (base::FeatureList::IsEnabled(network::features::kNetworkService))
     NOTREACHED();
 #endif
