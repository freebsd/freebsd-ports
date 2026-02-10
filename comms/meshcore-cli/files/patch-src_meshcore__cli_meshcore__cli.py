--- src/meshcore_cli/meshcore_cli.py.orig	2020-02-02 00:00:00 UTC
+++ src/meshcore_cli/meshcore_cli.py
@@ -9,8 +9,6 @@ import time, datetime
 import getopt, json, shlex, re
 import logging
 import requests
-from bleak import BleakScanner, BleakClient
-from bleak.exc import BleakError, BleakDBusError
 import serial.tools.list_ports
 from pathlib import Path
 import traceback
@@ -27,6 +25,13 @@ from prompt_toolkit.document import Document
 from Crypto.Cipher import AES
 from Crypto.Hash import HMAC, SHA256
 
+try:
+    from bleak import BleakScanner, BleakClient
+    from bleak.exc import BleakError, BleakDBusError
+    BLEAK_AVAILABLE = True
+except ImportError:
+    BLEAK_AVAILABLE = False
+
 import re
 
 from meshcore import MeshCore, EventType, logger
@@ -4307,16 +4312,17 @@ async def main(argv):
             case "-q": # quiet (turns logger to ERROR only)
                 quiet = True
             case "-l" :
-                print("BLE devices:")
-                try :
-                    devices = await BleakScanner.discover(timeout=timeout)
-                    if len(devices) == 0:
-                        print(" No ble device found")
-                    for d in devices :
-                        if not d.name is None and d.name.startswith("MeshCore-"):
-                            print(f" {d.address}  {d.name}")
-                except (BleakError, BleakDBusError):
-                    print(" No BLE HW")
+                if BLEAK_AVAILABLE:
+                    print("BLE devices:")
+                    try :
+                        devices = await BleakScanner.discover(timeout=timeout)
+                        if len(devices) == 0:
+                            print(" No ble device found")
+                        for d in devices :
+                            if not d.name is None and d.name.startswith("MeshCore-"):
+                                print(f" {d.address}  {d.name}")
+                    except (BleakError, BleakDBusError):
+                        print(" No BLE HW")
                 print("\nSerial ports:")
                 ports = serial.tools.list_ports.comports()
                 for port, desc, hwid in sorted(ports):
@@ -4325,13 +4331,14 @@ async def main(argv):
             case "-S" :
                 choices = []
 
-                try :
-                    devices = await BleakScanner.discover(timeout=timeout)
-                    for d in devices:
-                        if not d.name is None and d.name.startswith("MeshCore-"):
-                            choices.append(({"type":"ble","device":d}, f"{d.address:<22} {d.name}"))
-                except (BleakError, BleakDBusError):
-                    logger.info("No BLE Device")
+                if BLEAK_AVAILABLE:
+                    try :
+                        devices = await BleakScanner.discover(timeout=timeout)
+                        for d in devices:
+                            if not d.name is None and d.name.startswith("MeshCore-"):
+                                choices.append(({"type":"ble","device":d}, f"{d.address:<22} {d.name}"))
+                    except (BleakError, BleakDBusError):
+                        logger.info("No BLE Device")
 
                 ports = serial.tools.list_ports.comports()
                 for port, desc, hwid in sorted(ports):
@@ -4388,7 +4395,7 @@ async def main(argv):
         mc = await MeshCore.create_tcp(host=hostname, port=port, debug=debug, only_error=json_output)
     elif not serial_port is None : # connect via serial port
         mc = await MeshCore.create_serial(port=serial_port, baudrate=baudrate, debug=debug, only_error=json_output)
-    else : #connect via ble
+    elif BLEAK_AVAILABLE : #connect via ble
         client = None
         if device or address and len(address.split(":")) == 6 :
             pass
@@ -4471,6 +4478,9 @@ async def main(argv):
                     f.write(device.address)
                 elif not address is None:
                     f.write(address)
+
+    if mc is None:
+      return
 
     handle_message.mc = mc # connect meshcore to handle_message
     handle_advert.mc = mc
