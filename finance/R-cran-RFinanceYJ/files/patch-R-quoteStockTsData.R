--- R/quoteStockTsData.R.orig	2013-06-08 14:23:35.000000000 +0900
+++ R/quoteStockTsData.R	2013-06-27 20:47:46.000000000 +0900
@@ -38,7 +38,7 @@
     h <- as.number(xmlValue(quote.table.item[[3]]))
     l <- as.number(xmlValue(quote.table.item[[4]]))
     c <- as.number(xmlValue(quote.table.item[[5]]))
-    return(data.frame(date=d,open=o,height=h,low=l,close=c))
+    return(data.frame(date=d,open=o,high=h,low=l,close=c))
   }
   return(quoteTsData(x,function.fx,since,start.num,date.end,time.interval,type="fx"))
 }
@@ -66,6 +66,7 @@
   }
   
   while( result.num >= 51 ){
+    start.num <- start.num + 1
     quote.table <- NULL
     quote.url <- paste('http://info.finance.yahoo.co.jp/history/?code=',x,start,end,'&p=',start.num,'&tm=',substr(time.interval,1,1),sep="")
   
@@ -90,7 +91,6 @@
     }
     
     result.num <- xmlSize(quote.table)
-    start.num <- start.num + 1
     Sys.sleep(1)
   }
   financial.data <- financial.data[order(financial.data$date),]
@@ -99,7 +99,6 @@
 #convert string formart date to POSIXct object
 convertToDate <- function(date.string,time.interval)
 {
-  date.string <- iconv(date.string,"EUC-JP","UTF-8","")
   #data format is different between monthly and dialy or weekly
   if(any(time.interval==c('d','w'))){
     result <- gsub("^([0-9]{4})([^0-9]+)([0-9]{1,2})([^0-9]+)([0-9]{1,2})([^0-9]+)","\\1-\\3-\\5",date.string)
