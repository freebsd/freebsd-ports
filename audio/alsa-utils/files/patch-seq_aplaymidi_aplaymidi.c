--- seq/aplaymidi/aplaymidi.c.orig	2023-09-01 15:36:26 UTC
+++ seq/aplaymidi/aplaymidi.c
@@ -819,6 +819,8 @@ static void play_midi(void)
 		ev.time.tick = event->tick;
 		ev.dest = ports[event->port];
 		if (event->type == SND_SEQ_EVENT_TEMPO) {
+			snd_seq_ev_set_fixed(&ev);
+			ev.type = event->type;
 			ev.dest.client = SND_SEQ_CLIENT_SYSTEM;
 			ev.dest.port = SND_SEQ_PORT_SYSTEM_TIMER;
 			ev.data.queue.queue = queue;
