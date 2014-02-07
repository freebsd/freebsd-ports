--- engine/calculators/PayeeCalculator.cpp.orig
+++ engine/calculators/PayeeCalculator.cpp
@@ -59,14 +59,12 @@
   }
 
   std::multimap<Money, QString> moneymap;
-  std::map<QString, Money>::iterator it;
-  for( it = payeemap.begin(); it!= payeemap.end(); ++it ){
+  for( auto it = payeemap.begin(); it!= payeemap.end(); ++it ){
     moneymap.insert( std::make_pair( it->second, it->first ) );
   }
 
   int id = 0;
-  std::map<Money, QString>::iterator mit;
-  for( mit = moneymap.begin(); mit!= moneymap.end(); ++mit ){
+  for( auto mit = moneymap.begin(); mit!= moneymap.end(); ++mit ){
     CalculatorSeries cs( ++id );
     cs.addValue( mit->first );
 
