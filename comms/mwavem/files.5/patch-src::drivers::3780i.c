
$FreeBSD$

--- src/drivers/3780i.c	2002/12/11 00:57:53	1.1
+++ src/drivers/3780i.c	2002/12/11 00:59:00
@@ -419,7 +419,7 @@
   /* Transfer the memory block */
   while (uCount-- !=0) {
     val=InWordDsp(DSP_MsaDataDSISHigh);
-    if (susword (pusBuffer++, val))
+    if (suword16 (pusBuffer++, val))
 	return EFAULT;
     
     PRINTK_3(TRACE_3780I,"3780I::dsp3780I_ReadDStore uCount %x val %x\n",uCount,val);
@@ -450,7 +450,7 @@
   /* Transfer the memory block */
   while (uCount-- !=0) {
     val=InWordDsp(DSP_ReadAndClear);
-    if (susword (pusBuffer++, val))
+    if (suword16 (pusBuffer++, val))
 	return EFAULT;
     
     PRINTK_3(TRACE_3780I,"3780I::dsp3780I_ReadAndCleanDStore uCount %x val %x\n",uCount,val); 
@@ -481,7 +481,7 @@
   /* Transfer the memory block */
   while (uCount-- !=0) {
     int val;
-    if ( (val = fusword (pusBuffer++)) == -1) return EFAULT;
+    if ( (val = fuword16 (pusBuffer++)) == -1) return EFAULT;
     OutWordDsp(DSP_MsaDataDSISHigh, val);
     
      PRINTK_3(TRACE_3780I,"3780I::dsp3780I_WriteDStore uCount %x val %x\n",uCount,val);
@@ -518,12 +518,12 @@
     s = splhigh();
     val_lo=InWordDsp(DSP_MsaDataISLow);
     val_hi=InWordDsp(DSP_MsaDataDSISHigh);
-    if (susword (pusBuffer++, val_lo)) 
+    if (suword16 (pusBuffer++, val_lo)) 
 	{
 	splx (s);
 	return EFAULT;
 	}
-    if (susword (pusBuffer++, val_hi))
+    if (suword16 (pusBuffer++, val_hi))
 	{
 	splx (s);
 	return EFAULT;
@@ -560,8 +560,8 @@
   while (uCount-- !=0) {
     int val_lo,val_hi;
     int s;
-    if ( (val_lo = fusword (pusBuffer++)) == -1) return EFAULT;
-    if ( (val_hi = fusword (pusBuffer++)) == -1) return EFAULT;
+    if ( (val_lo = fuword16 (pusBuffer++)) == -1) return EFAULT;
+    if ( (val_hi = fuword16 (pusBuffer++)) == -1) return EFAULT;
     s = splhigh();
     OutWordDsp(DSP_MsaDataISLow, val_lo);
     OutWordDsp(DSP_MsaDataDSISHigh, val_hi);
