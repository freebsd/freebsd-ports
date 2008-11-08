--- Output/JACKaudiooutput.C.orig	2008-07-23 14:05:40.000000000 +0200
+++ Output/JACKaudiooutput.C	2008-07-23 14:06:33.000000000 +0200
@@ -38,6 +38,7 @@
     jackmaster=master_;
     jackclient=0;
     char tmpstr[100];
+    const char **ports;
 
     for (int i=0;i<15;i++){
 	if (i!=0) snprintf(tmpstr,100,"ZynAddSubFX_%d",i);
@@ -75,6 +76,15 @@
     jack_connect(jackclient,jack_port_name(outport_left),"alsa_pcm:out_1");
     jack_connect(jackclient,jack_port_name(outport_right),"alsa_pcm:out_2");
      */
+
+    if ((ports = jack_get_ports (jackclient, NULL, NULL, JackPortIsPhysical|JackPortIsInput)) == NULL) 
+	fprintf(stderr,"Cannot connect to jack output, you may hear no sound\n");       else {
+      if (jack_connect(jackclient,jack_port_name(outport_left),ports[0]))
+	fprintf(stderr,"Cannot connect to left output port\n");
+      if (jack_connect(jackclient,jack_port_name(outport_right),ports[1]))
+	fprintf(stderr,"Cannot connect to right output port\n");
+    }
+     
      return(true);
 };
 
@@ -114,13 +124,13 @@
   jack_midi_event_t jack_midi_event;
   jack_nframes_t event_index = 0;
   jack_nframes_t event_count = 
-    jack_midi_port_get_info(midi_buf, frames)->event_count;
+    jack_midi_get_event_count(midi_buf);
   unsigned char* midi_data;
   unsigned char type, chan;
   
   while (event_index < event_count) {
     
-    jack_midi_event_get(&jack_midi_event, midi_buf, event_index, frames);
+    jack_midi_event_get(&jack_midi_event, midi_buf, event_index);
     midi_data = jack_midi_event.buffer;
     type = midi_data[0] & 0xF0;
     chan = midi_data[0] & 0x0F;
