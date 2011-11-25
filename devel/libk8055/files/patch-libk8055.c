--- libk8055.c	2006-07-29 11:02:26.000000000 +0100
+++ libk8055.c.orig	2011-10-09 21:34:57.693521803 +0100
@@ -83,7 +83,7 @@
           return -1; /*throw -1 to show that OpenDevice failed */
 	}
         else 
-	  open_status=usb_interrupt_read(device_handle,0x81,data_in,8,20);
+	  open_status=usb_interrupt_read(device_handle,0x81,(char *)data_in,8,20);
 	if (open_status!=8)
 	  return -1;
 	else
@@ -101,7 +101,7 @@
 
 long ReadAnalogChannel(long Channelno){
 	int open_status=0;
-	open_status=usb_interrupt_read(device_handle,0x81,data_in,8,20);
+	open_status=usb_interrupt_read(device_handle,0x81,(char *)data_in,8,20);
 	if (open_status==8){
   	  if (Channelno==2)
 	    return data_in[3];
@@ -114,7 +114,7 @@
 
 int ReadAllAnalog(long* data1, long* data2){
 	int open_status=0;
-	open_status=usb_interrupt_read(device_handle,0x81,data_in,8,20);
+	open_status=usb_interrupt_read(device_handle,0x81,(char *)data_in,8,20);
 	if (open_status==8){
 	  *data1=data_in[2];
 	  *data2=data_in[3];
@@ -131,8 +131,8 @@
 	  data_out[3]=(unsigned char)data;
 	else
 	  data_out[2]=(unsigned char)data;
-	open_status=usb_interrupt_write(device_handle,0x01,data_out,8,20);
-	open_status=usb_interrupt_write(device_handle,0x01,data_out,8,20);
+	open_status=usb_interrupt_write(device_handle,0x01,(char *)data_out,8,20);
+	open_status=usb_interrupt_write(device_handle,0x01,(char *)data_out,8,20);
 	if (open_status!=8)
 	  return -1;
 	else
@@ -144,8 +144,8 @@
 	data_out[0]=0x05; /* analog out or digital out command */
 	  data_out[2]=(unsigned char)data1;
 	  data_out[3]=(unsigned char)data2;
-	open_status=usb_interrupt_write(device_handle,0x01,data_out,8,20);
-	open_status=usb_interrupt_write(device_handle,0x01,data_out,8,20);
+	open_status=usb_interrupt_write(device_handle,0x01,(char *)data_out,8,20);
+	open_status=usb_interrupt_write(device_handle,0x01,(char *)data_out,8,20);
 	if (open_status!=8)
 	  return -1;
 	else
@@ -179,8 +179,8 @@
         int open_status=0;
         data_out[0]=0x05; /* analog out or digital out command */
         data_out[1]=(unsigned char)data;
-        open_status=usb_interrupt_write(device_handle,0x01,data_out,8,20);
-        open_status=usb_interrupt_write(device_handle,0x01,data_out,8,20);
+        open_status=usb_interrupt_write(device_handle,0x01,(char *)data_out,8,20);
+        open_status=usb_interrupt_write(device_handle,0x01,(char *)data_out,8,20);
         if (open_status!=8)
           return -1;
         else
@@ -225,7 +225,7 @@
 	int open_status=0,i;
 	unsigned char mask=8;
 	if (channel>0 && channel<6){
-	  open_status=usb_interrupt_read(device_handle,0x81,data_in,8,20);
+	  open_status=usb_interrupt_read(device_handle,0x81,(char *)data_in,8,20);
 	  if (open_status==8){
 	    for (i=1;i<=channel;i++)
 	      if (i!=3) mask*=2;
@@ -244,7 +244,7 @@
 long ReadAllDigital(){
 	int open_status=0,i,return_data=0;
 	unsigned char mask=8,pow=1;
-	open_status=usb_interrupt_read(device_handle,0x81,data_in,8,20);
+	open_status=usb_interrupt_read(device_handle,0x81,(char *)data_in,8,20);
 	if (open_status==8){
 	    for (i=1;i<=5;i++){
 	      mask*=2;
@@ -269,8 +269,8 @@
 	if (counternr==1 || counternr==2){
           data_out[0]=0x02+(unsigned char)counternr; /* counter selection */
 	  data_out[3+counternr]=0x00;
-	  open_status=usb_interrupt_write(device_handle,0x01,data_out,8,20);
-	  open_status=usb_interrupt_write(device_handle,0x01,data_out,8,20);
+	  open_status=usb_interrupt_write(device_handle,0x01,(char *)data_out,8,20);
+	  open_status=usb_interrupt_write(device_handle,0x01,(char *)data_out,8,20);
 	  if (open_status==8)
 	    return 0;
 	  else
@@ -283,7 +283,7 @@
 long ReadCounter(long counterno){
 	int open_status=0;
 	if (counterno==1 || counterno==2){
-  	  open_status=usb_interrupt_read(device_handle,0x81,data_in,8,20);
+  	  open_status=usb_interrupt_read(device_handle,0x81,(char *)data_in,8,20);
 	  if (open_status==8){
   	    if (counterno==2)
 	      return data_in[6];
@@ -316,7 +316,7 @@
 	    value+=1;
 	  data_out[5+counterno]=(unsigned char)value;
 	  if (DEBUG) fprintf(stderr,"Debouncetime%d value for k8055:%d\n",(int)counterno,data_out[5+counterno]);
-  	  open_status=usb_interrupt_write(device_handle,0x01,data_out,8,20);
+  	  open_status=usb_interrupt_write(device_handle,0x01,(char *)data_out,8,20);
 	  if (open_status==8)
   	    return 0;
 	  else
