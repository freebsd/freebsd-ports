#!/usr/bin/env python3
"""update.py for dnsmasq-devel - (C) 2025 Matthias Andree, placed under MIT license
To use, edit Makefile with the new version,
then run files/update.py, which will download, check sigs, if GnuPG checks out, update makesum,
upload tarball and sig to my public_distfiles/ because upstream has low bandwidth, and test build.

If things work out, commit manually and push."""

import os
import shutil
import subprocess
import sys

def trace(func):
    def wrapper(*args, **kwargs):
        print(f"\n> {func.__name__}({args}, {kwargs})", file=sys.stderr)
        retval = func(*args, **kwargs)
        print(f"< {func.__name__} -> {retval!r}", file=sys.stderr)
        return retval
    return wrapper

traced_run = trace(subprocess.run)

cleanenv={'LC_ALL': 'C.UTF-8',
          'PATH': os.environ["PATH"]}
defargs={"check": "True", "env": cleanenv, "encoding": 'UTF-8'}

try:
    distdir, master_site, files_dir, dist_dir = map(str.strip, traced_run(['make', '-V', 'DISTDIR',
                                                                           '-V', 'MASTER_SITES:N*FreeBSD*',
                                                                           '-V', 'FILESDIR',
                                                                           '-V', 'DISTDIR'],
                                                                          capture_output=True, **defargs).stdout.splitlines())
    filename_tarball = traced_run('make -V DISTFILES'.split(), capture_output=True, **defargs).stdout.splitlines()[0].strip()
    filename_signature = filename_tarball + '.asc'
    uri_tarball = master_site + filename_tarball
    uri_signature = master_site + filename_signature
    traced_run(['fetch', uri_tarball, uri_signature], **defargs)
    traced_run(['gpg', '--no-options', '--with-colons', '--status-fd', '1',
                                        '--no-default-keyring', '--keyring', files_dir + '/simon-kelley-keyring.asc',
                                        '--verify', filename_signature, filename_tarball], **defargs)
    traced_run(['rsync', '-avHPW', '--chmod=0644', filename_tarball, filename_signature, 'freefall.freebsd.org:public_distfiles/'], **defargs)
    shutil.move(filename_tarball, dist_dir + '/' + filename_tarball)
    traced_run(['make', 'makesum', 'clean'], **defargs)
    os.remove(filename_signature)
    traced_run(['make', 'check-plist', 'package'], **defargs)
    print("\nSUCCESS\n")
except Exception as cpe:
    print("\nERROR\n")
    print(repr(cpe))
    print("\nERROR\n")
    sys.exit(1)
