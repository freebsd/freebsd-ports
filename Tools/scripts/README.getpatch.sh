getpatch.sh is a shell script to help me dealing
with bugzilla attachements.

Usage: getpatch [-dp] <num> <num> ...
 -d : download deprecate patches too
 -p : store the patches in the current dir, instead of the dedicated directory
use the GETPATCH_DIR variable to define the root location for the downloaded patches

Exemple1: simple usage
% getpatch 197844
Bug ID: 197844
 + attachment 153202-fcgi.diff is obsolete, skip
 + attachment 153215-fcgi.diff download success
 >> Patches stored in /tmp/197844

Exemple2: download deprecated too
getpatch -d 197844
Bug ID: 197844
 + attachment 153202-fcgi.diff download success
 + attachment 153215-fcgi.diff download success
 >> Patches stored in /tmp/197844

Exemple3: don't create a dedicate directory
% getpatch -p 197844
Bug ID: 197844
 + attachment 153202-fcgi.diff is obsolete, skip
 + attachment 153215-fcgi.diff download success
 >> Patches stored in /tmp

Exemple4: use GETPATCH_DIR
% setenv GETPATCH_DIR ~/patch-store/
% getpatch  197844
Bug ID: 197844
 + attachment 153202-fcgi.diff is obsolete, skip
 + attachment 153215-fcgi.diff download success
 >> Patches stored in /usr/home/rodrigo/patch-store/197844

