--- src/jackbackend.h
+++ src/jackbackend.h
@@ -0,0 +1,23 @@
+/*
+ * jackbackend.h
+ * JACK audio and MIDI backends.
+ *
+ * for Denemo, a gtk+ frontend to GNU Lilypond
+ * Copyright (C) 2011  Dominic SacrÃ©
+ *
+ * This program is free software: you can redistribute it and/or modify
+ * it under the terms of the GNU General Public License as published by
+ * the Free Software Foundation, either version 3 of the License, or
+ * (at your option) any later version.
+ */
+
+#ifndef JACKBACKEND_H
+#define JACKBACKEND_H
+
+#include "audiointerface.h"
+
+extern backend_t jack_audio_backend;
+extern backend_t jack_midi_backend;
+
+
+#endif // JACKBACKEND_H
