#!/usr/bin/env python3
"""update.py for dnsmasq-devel - (C) 2025 Matthias Andree, placed under MIT license
To use, edit Makefile with the new version and possibly URLBASE below when switching to release-candidates,
then run python update.py, which will download, check sigs, if GnuPG checks out, update makesum,
upload tarball and sig to my public_distfiles/ because upstream has low bandwidth, and test build.

If things work out, commit manually and push."""

URLBASE = 'https://www.thekelleys.org.uk/dnsmasq/test-releases/'

import os
import shutil
import subprocess
import sys

def trace(func):
    def wrapper(*args, **kwargs):
        print(f"> {func.__name__}({args}, {kwargs})", file=sys.stderr)
        retval = func(*args, **kwargs)
        print(f"< {func.__name__} -> {retval!r}", file=sys.stderr)
        return retval
    return wrapper

subprocess.run = trace(subprocess.run)

completed_distname = subprocess.run('make -V DISTNAME'.split(), capture_output=True, check=True, env={"LC_ALL": "C.UTF-8", "PATH": f'{os.environ["PATH"]}'}, encoding='UTF-8')
name = completed_distname.stdout.splitlines()[0].strip()
fnt = name + '.tar.xz'
fns = fnt + '.asc'
urt = URLBASE + fnt
urs = URLBASE + fns
subprocess.run(['fetch', urt, urs], check=True)
subprocess.run(['gpg', '--verify', fns, fnt], check=True)
subprocess.run(['rsync', '-avHP', '--chmod=0644', fnt, fns, 'freefall.freebsd.org:public_distfiles/'], check=True)
shutil.move(fnt, '/usr/ports/distfiles/' + fnt)
os.remove(fns)
subprocess.run(['make', 'makesum'], check=True)
subprocess.run(['make', 'clean'], check=True)
subprocess.run(['make', 'check-plist', 'package'], check=True)
