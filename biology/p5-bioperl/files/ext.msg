---------------------------------------------------------------------------
This port includes support for a number of optional extensions to Bioperl.
To build the port with these extensions, set the corresponding variables:

To build with client-side CORBA support:	set WITH_CORBA_CLIENT
To build with server-side CORBA support:	set WITH_CORBA_SERVER
To build with (experimental) GUI support:	set WITH_GUI

Additionally, the variable WITH_CORBA implies both WITH_CORBA_CLIENT and
WITH_CORBA_SERVER.

For example, to build and install the Bioperl port with all the currently
available optional extensions:

  make WITH_CORBA=yes WITH_GUI=yes install
---------------------------------------------------------------------------
