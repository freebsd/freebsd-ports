--- R/quoteStockTsData.R.orig	2013-08-12 15:05:58 UTC
+++ R/quoteStockTsData.R
@@ -46,42 +46,34 @@ quoteFXTsData <- function(x, since=NULL,
 #get time series data from Yahoo! Finance.
 quoteTsData <- function(x,function.financialproduct,since,start.num,date.end,time.interval,type="stock"){
   r <- NULL
-  result.num <- 51
   financial.data <- data.frame(NULL)
-  #start <- (gsub("([0-9]{4,4})-([0-9]{2,2})-([0-9]{2,2})","&c=\\1&a=\\2&b=\\3",since))
-  #end   <- (gsub("([0-9]{4,4})-([0-9]{2,2})-([0-9]{2,2})","&f=\\1&d=\\2&e=\\3",date.end))
   start <- (gsub("([0-9]{4,4})-([0-9]{2,2})-([0-9]{2,2})","&sy=\\1&sm=\\2&sd=\\3",since))
   end   <- (gsub("([0-9]{4,4})-([0-9]{2,2})-([0-9]{2,2})","&ey=\\1&em=\\2&ed=\\3",date.end))
 
   if(!any(time.interval==c('d','w','m'))) stop("Invalid time.interval value")
-  
-  extractQuoteTable <- function(r,type){
-    if(type %in% c("fund","fx")){
-      tbl <- r[[2]][[2]][[7]][[3]][[3]][[9]][[2]]
-    }
-    else{
-      tbl <- r[[2]][[2]][[7]][[3]][[3]][[10]][[2]]
-    }
-    return(tbl)
-  }
-  
-  while( result.num >= 51 ){
+  while( 1 ){
     start.num <- start.num + 1
     quote.table <- NULL
-    quote.url <- paste('http://info.finance.yahoo.co.jp/history/?code=',x,start,end,'&p=',start.num,'&tm=',substr(time.interval,1,1),sep="")
+    quote.url <- paste('https://info.finance.yahoo.co.jp/history/?code=',x,start,end,'&p=',start.num,'&tm=',substr(time.interval,1,1),sep="")
+    quote.html <- getURL(quote.url)
   
-    try( r <- xmlRoot(htmlTreeParse(quote.url,error=xmlErrorCumulator(immediate=F))), TRUE)
+    try( r <- htmlParse(quote.html) )
     if( is.null(r) ) stop(paste("Can not access :", quote.url))
 
-    #try( quote.table <- r[[2]][[1]][[1]][[16]][[1]][[1]][[1]][[4]][[1]][[1]][[1]], TRUE )
-    try( quote.table <- extractQuoteTable(r,type), TRUE )
+    try( quote.table <- xpathApply(r,"//table")[[2]], TRUE )
+
+    quote.size <- xmlSize(quote.table)
+
+    if( xmlSize(quote.table) <= 1 ){
+      return(financial.data)
+    }
     
     if( is.null(quote.table) ){
       if( is.null(financial.data) ){
         stop(paste("Can not quote :", x))
       }else{
-         financial.data <- financial.data[order(financial.data$date),]
-         return(financial.data)
+        financial.data <- financial.data[order(financial.data$date),]
+        return(financial.data)
       }
     }
 
@@ -90,7 +82,6 @@ quoteTsData <- function(x,function.finan
       financial.data <- rbind(financial.data,function.financialproduct(quote.table[[i]]))
     }
     
-    result.num <- xmlSize(quote.table)
     Sys.sleep(1)
   }
   financial.data <- financial.data[order(financial.data$date),]
@@ -120,5 +111,3 @@ endOfMonth <- function(date.obj)
   return(startOfNextMonth-1)
 }
 
-
-
