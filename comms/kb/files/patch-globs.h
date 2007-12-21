--- globs.h.orig	2007-07-20 10:26:01.000000000 -0400
+++ globs.h	2007-11-23 09:38:53.000000000 -0500
@@ -169,8 +169,15 @@
                      "<18.0>", "<19.2>", "<20.6>", "<22.2>", "<24.0>",
                      "<26.2>", "<28.8>", "<32.0>", "<36.0>", "<41.1>",
                      "<48.0>", "<57.6>", "<72.0>"};
+/* These device names are really specific to FreeBSD -db */
+#ifdef BSD
+static const gchar *port_bracket[6] = {"<OFF>", "<ttyd0>", "<ttyd1>",
+                                       "<ttyU0>", "<ttyU1>", "<TELNET>"};
+#else
 static const gchar *port_bracket[6] = {"<OFF>", "<ttyS0>", "<ttyS1>",
                                        "<ttyUSB0>", "<ttyUSB1>", "<TELNET>"};
+#endif
+
 static const gchar *yn_bracket[2] = {"<YES>", "<NO>"};
 static const gchar *dupe_bracket[2] = {"<ASK>", "<ALWAYS>"};
 static const gchar *partial_bracket[3] = {"<NO>", "<2>", "<3>"};
@@ -178,7 +185,7 @@
                     " Station Call Sign", "Operator Call Sign",
                     "     Operator Name", "           Address",
                     "           Address", "              City",
-                    "             State", "          Zip Code",
+                    "    State/Province", "   Zip/Postal Code",
                     "          Latitude", "         Longitude",
                     "     Offset to UTC", "    Entry Category",
                     "             Power", "      Contest Type",
