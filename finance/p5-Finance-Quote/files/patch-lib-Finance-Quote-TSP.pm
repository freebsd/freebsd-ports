http://github.com/pfenwick/finance-quote/commit/97f8741c90af7c637c2fc990c4245c7e56eb3087

--- lib/Finance/Quote/TSP.pm.orig	2009-10-06 01:39:57.000000000 +0800
+++ lib/Finance/Quote/TSP.pm	2010-11-05 19:26:46.000000000 +0800
@@ -43,7 +43,7 @@
 
 # URLs of where to obtain information
 
-$TSP_URL = 'http://www.tsp.gov/rates/share-prices.html';
+$TSP_URL = 'https://www.tsp.gov/investmentfunds/shareprice/sharePriceHistory.shtml';
 $TSP_MAIN_URL=("http://www.tsp.gov");
 
 %TSP_FUND_COLUMNS = (
