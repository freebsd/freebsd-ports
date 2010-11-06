http://github.com/pfenwick/finance-quote/commit/7de984bea80e9c5e00504ededba6897183bb8c45

--- lib/Finance/Quote.pm.orig	2009-10-06 01:39:57.000000000 +0800
+++ lib/Finance/Quote.pm	2010-02-13 18:25:22.000000000 +0800
@@ -167,7 +167,7 @@
   if (!@reqmodules or $reqmodules[0] eq "-defaults") {
     shift(@reqmodules) if (@reqmodules);
     # Default modules
-    @modules = qw/AEX AIAHK ASEGR ASX BMONesbittBurns Bourso Cdnfundlibrary
+    @modules = qw/AEX AIAHK ASEGR ASX BMONesbittBurns BSERO Bourso Cdnfundlibrary
             Currencies Deka DWS FTPortfolios Fidelity FinanceCanada Fool HU
             GoldMoney HEX
             IndiaMutual LeRevenu ManInvestments Morningstar NZX Platinum SEB
