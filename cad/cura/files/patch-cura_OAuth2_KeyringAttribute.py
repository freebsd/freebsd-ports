--- cura/OAuth2/KeyringAttribute.py.orig	2022-04-28 04:59:10 UTC
+++ cura/OAuth2/KeyringAttribute.py
@@ -5,7 +5,7 @@ from typing import Type, TYPE_CHECKING, Optional, List
 from io import BlockingIOError
 import keyring
 from keyring.backend import KeyringBackend
-from keyring.errors import NoKeyringError, PasswordSetError, KeyringLocked
+from keyring.errors import PasswordSetError, KeyringLocked
 
 from UM.Logger import Logger
 
