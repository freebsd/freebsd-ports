Description: Backport upstream a5590bb: handle the private
  multiprocessing.connection challenge constants of Python 3.12.
Issue ID: none
Changeset: https://github.com/dabeaz/curio/commit/a5590bb
TODO: Upstream was archived on 2025-12-21, no further release expected; keep.

--- curio/channel.py.orig	2022-10-25 14:18:45 UTC
+++ curio/channel.py
@@ -28,9 +28,16 @@ AUTH_MESSAGE_LENGTH = mpc.MESSAGE_LENGTH    # 20
 # Authentication parameters (copied from multiprocessing)
 
 AUTH_MESSAGE_LENGTH = mpc.MESSAGE_LENGTH    # 20
-CHALLENGE = mpc.CHALLENGE                   # b'#CHALLENGE#'
-WELCOME = mpc.WELCOME                       # b'#WELCOME#'
-FAILURE = mpc.FAILURE                       # b'#FAILURE#'
+try:
+    # Python 3.12+
+    CHALLENGE = mpc._CHALLENGE              # b'#CHALLENGE#'
+    WELCOME = mpc._WELCOME                  # b'#WELCOME#'
+    FAILURE = mpc._FAILURE                  # b'#FAILURE#'
+except AttributeError:
+    # Python 3.7-3.11
+    CHALLENGE = mpc.CHALLENGE               # b'#CHALLENGE#'
+    WELCOME = mpc.WELCOME                   # b'#WELCOME#'
+    FAILURE = mpc.FAILURE                   # b'#FAILURE#'
 
 
 
