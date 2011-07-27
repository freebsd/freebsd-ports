diff --git a/scripts/install.sh b/scripts/install.sh
index 3d71e63..2a40727 100755
--- scripts/install.sh.orig
+++ scripts/install.sh
@@ -15,16 +15,16 @@ LIBPATH=${PREFIX}/msp430/lib
 mkdir -p ${INCPATH} ${LIBPATH}
 
 # Upstream headers
-install -p ${UPSTREAM}/*.h ${INCPATH}
+install -m 0644 -p ${UPSTREAM}/*.h ${INCPATH}
 
 # Local override headers
-install -p ${MSP430MCU_ROOT}/include/*.h ${INCPATH}
+install -m 0644 -p ${MSP430MCU_ROOT}/include/*.h ${INCPATH}
 
 # Override msp430.h to accommodate legacy MSPGCC MCU identifiers
-install -p ${ANALYSIS}/msp430.h ${INCPATH}
+install -m 0644 -p ${ANALYSIS}/msp430.h ${INCPATH}
 
 # MCU-specific data for GCC driver program
-install -p ${ANALYSIS}/msp430mcu.spec ${LIBPATH}
+install -m 0644 -p ${ANALYSIS}/msp430mcu.spec ${LIBPATH}
 
 # Install MCU-specific memory and periph maps
 cp -pr ${ANALYSIS}/ldscripts ${LIBPATH}
