On Thu, Jan 31, 2008 at 02:02:31PM +0100, Erwin Lansing wrote:
> This looks like the port itself needs fixing, either by making it use
> bsdar, or having a mechanism to install GNU ar from a port.  Anyway, not
> a problem with bsdar itself :-)

This one is less-common, it has a its own perl script to grep string
"GNU ar" out of `ar --version`. However later it listed acceptable 'ar' of
several OSes. So I tried a fix like this and it works:

--- conflib.pl.orig	2008-01-31 20:44:29.000000000 +0100
+++ conflib.pl	2008-01-31 20:45:31.000000000 +0100
@@ -1407,7 +1407,7 @@
    }
  # I think all ar tools are usable but ...
  if (($OSf eq 'Darwin') || ($OSf eq 'HP-UX') || ($OSf eq 'Tru64') ||
-     ($OSf eq 'Solaris'))
+     ($OSf eq 'Solaris') || ($OSf eq 'FreeBSD'))
    {
     $conf{'GNU_AR'}='ar';
     $conf{'UseRanLib'}=1;


