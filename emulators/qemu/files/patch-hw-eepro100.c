Index: qemu/hw/eepro100.c
@@ -729,6 +729,7 @@
                 logout
                     ("TBD (simplified mode): buffer address 0x%08x, size 0x%04x\n",
                      tx_buffer_address, tx_buffer_size);
+                assert(size + tx_buffer_size <= sizeof(buf));
                 cpu_physical_memory_read(tx_buffer_address, &buf[size],
                                          tx_buffer_size);
                 size += tx_buffer_size;
@@ -749,9 +750,13 @@
                         logout
                             ("TBD (extended mode): buffer address 0x%08x, size 0x%04x\n",
                              tx_buffer_address, tx_buffer_size);
-                        cpu_physical_memory_read(tx_buffer_address, &buf[size],
-                                                 tx_buffer_size);
-                        size += tx_buffer_size;
+                        if (size + tx_buffer_size > sizeof(buf)) {
+                            logout("bad extended TCB with size 0x%04x\n", tx_buffer_size);
+                        } else {
+                            cpu_physical_memory_read(tx_buffer_address, &buf[size],
+                                                     tx_buffer_size);
+                            size += tx_buffer_size;
+                        }
                         if (tx_buffer_el & 1) {
                             break;
                         }
@@ -766,14 +771,20 @@
                     logout
                         ("TBD (flexible mode): buffer address 0x%08x, size 0x%04x\n",
                          tx_buffer_address, tx_buffer_size);
-                    cpu_physical_memory_read(tx_buffer_address, &buf[size],
-                                             tx_buffer_size);
-                    size += tx_buffer_size;
+                    if (size + tx_buffer_size > sizeof(buf)) {
+                        logout("bad flexible TCB with size 0x%04x\n", tx_buffer_size);
+                    } else {
+                        cpu_physical_memory_read(tx_buffer_address, &buf[size],
+                                                 tx_buffer_size);
+                        size += tx_buffer_size;
+                    }
                     if (tx_buffer_el & 1) {
                         break;
                     }
                 }
             }
+            logout("%p sending frame, len=%d,%s\n", s, size, nic_dump(buf, size));
+            assert(size <= sizeof(buf));
             qemu_send_packet(s->vc, buf, size);
             s->statistics.tx_good_frames++;
             /* Transmit with bad status would raise an CX/TNO interrupt.
