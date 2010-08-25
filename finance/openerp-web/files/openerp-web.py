#!/usr/bin/env python
# EASY-INSTALL-ENTRY-SCRIPT: 'openerp-web==5.0.6','console_scripts','openerp-web'
__requires__ = 'openerp-web==5.0.11'
import sys
from pkg_resources import load_entry_point

sys.exit(
   load_entry_point('openerp-web==5.0.11', 'console_scripts', 'openerp-web')()
)
