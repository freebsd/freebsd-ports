--- ../include/Schematic.h.orig	Fri Mar 30 18:50:58 2001
+++ ../include/Schematic.h	Fri Aug 20 21:48:46 2004
@@ -91,9 +91,9 @@
   QList<DataPoint>& getZData();
   TComplex getPortImpedance( uint port );
   
-private:
   Schematic( const Schematic& );
 
+private:
   int distanceFromLine( const QPoint& point,
 			const CircuitLine& line,
 			bool orthoganalOnly );
