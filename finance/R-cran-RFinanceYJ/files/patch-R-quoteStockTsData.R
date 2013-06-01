--- R/quoteStockTsData.R.orig	2011-03-24 23:34:43.000000000 +0900
+++ R/quoteStockTsData.R	2013-06-02 04:03:12.000000000 +0900
@@ -56,7 +56,7 @@
     try( r <- xmlRoot(htmlTreeParse(quote.url,error=xmlErrorCumulator(immediate=F))), TRUE)
     if( is.null(r) ) stop(paste("Can not access :", quote.url))
 
-    try( quote.table <- r[[2]][[1]][[1]][[16]][[1]][[1]][[1]][[4]][[1]][[1]][[1]], TRUE )
+    try( quote.table <- r[[2]][[1]][[1]][[13]][[1]][[1]][[1]][[4]][[1]][[1]][[1]], TRUE )
     #
     if( is.null(quote.table) ){
       if( is.null(financial.data) ){
