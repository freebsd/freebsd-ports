---------------------------------------------------------------------------
Biopython is currently being built without CORBA support.  If you wish to
enable the optional CORBA support, set the WITH_CORBA variable, e.g.:

  make WITH_CORBA=yes install

If you set WITH_CORBA, you may optionally also set the CORBA_ORB variable
to "omniorb", "fnorb" or "orbit".  If you do not, "omniorb" is assumed as
default.

Further details are provided in the comments in this port's Makefile.
---------------------------------------------------------------------------
