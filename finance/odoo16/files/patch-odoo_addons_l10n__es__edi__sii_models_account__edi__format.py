Description: urllib3 2 removed urllib3.util.ssl_.DEFAULT_CIPHERS, so the
  Spanish SII e-invoicing module failed to import. Use the OpenSSL
  "DEFAULT:!DH" cipher string instead, as upstream does since 18.0.
Issue ID: none
Changeset: https://github.com/odoo/odoo/blob/18.0/addons/l10n_es_edi_sii/models/account_edi_format.py
TODO: Odoo 16 is in maintenance; keep locally.

--- odoo/addons/l10n_es_edi_sii/models/account_edi_format.py.orig	2026-10-14 01:38:17 UTC
+++ odoo/addons/l10n_es_edi_sii/models/account_edi_format.py
@@ -1,7 +1,7 @@ from collections import defaultdict
 # -*- coding: utf-8 -*-
 # Part of Odoo. See LICENSE file for full copyright and licensing details.
 from collections import defaultdict
-from urllib3.util.ssl_ import create_urllib3_context, DEFAULT_CIPHERS
+from urllib3.util.ssl_ import create_urllib3_context
 from urllib3.contrib.pyopenssl import inject_into_urllib3
 from OpenSSL.crypto import load_certificate, load_privatekey, FILETYPE_PEM
 
@@ -14,7 +14,8 @@ import requests
 
 
 # Custom patches to perform the WSDL requests.
-EUSKADI_CIPHERS = f"{DEFAULT_CIPHERS}:!DH"
+# urllib3 2 removed DEFAULT_CIPHERS; use the OpenSSL default list, as Odoo 18 does
+EUSKADI_CIPHERS = "DEFAULT:!DH"
 
 
 class PatchedHTTPAdapter(requests.adapters.HTTPAdapter):
