--- src/actgate.cpp.orig	2022-10-30 18:41:27 UTC
+++ src/actgate.cpp
@@ -138,7 +138,7 @@ void Entity::actGate()
 		//Opening gate.
 		if ( this->z > gateStartHeight - 12 )
 		{
-			this->z = std::max(gateStartHeight - 12, this->z - 0.25);
+			this->z = std::max(gateStartHeight - 12, this->z - (real_t)0.25);
 
 			// rattle the gate
 			gateRattle = (gateRattle == 0);
