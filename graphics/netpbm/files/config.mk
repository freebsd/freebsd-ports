# $FreeBSD$
CFLAGS_SHLIB += -fPIC
DEFAULT_TARGET = nonmerge
INSTALL_PERM_BIN =  $(BINMODE)
INSTALL_PERM_DATA = $(DATAMODE)
INSTALL_PERM_HDR =  $(DATAMODE)
INSTALL_PERM_LIBD = $(DIRMODE)
INSTALL_PERM_LIBS = $(SHAREMODE)
INSTALL_PERM_MAN =  $(MANMODE)
JASPERHDR_DIR = $(LOCALBASE)/include
JASPERLIB = -L$(LOCALBASE)/lib -ljasper -ljpeg
JBIGHDR_DIR = $(LOCALBASE)/include
JBIGLIB = -L$(LOCALBASE)/lib -ljbig
JPEGHDR_DIR = $(LOCALBASE)/include
JPEGLIB = -L$(LOCALBASE)/lib -ljpeg
LINKER_CAN_DO_EXPLICIT_LIBRARY = Y
LINKERISCOMPILER = Y
NETPBMLIBSUFFIX = so
NETPBMLIBTYPE = unixshared
NETPBM_DOCURL = http://netpbm.sourceforge.net/doc/
PNGHDR_DIR = $(LOCALBASE)/include
PNGLIB = -L$(LOCALBASE)/lib -lpng
RGB_DB_PATH = $(DATADIR)/rgb.txt:$(LOCALBASE)/lib/X11/rgb.txt
STATICLIB_TOO = Y
TIFFHDR_DIR = $(LOCALBASE)/include
TIFFLIB = -L$(LOCALBASE)/lib -ltiff -llzma -ljbig
X11HDR_DIR = $(LOCALBASE)/include
X11LIB = -L$(LOCALBASE)/lib -lX11 -lxcb -lXau -lXdmcp
ZLIB = -lz
# Don't use pkg-config.  It leads to all sorts of "fun" results when
# trying to link netpbm's programs statically.  This is only an issue
# when building the port outside of Poudriere/Synth.
PKG_CONFIG = false
PNGVER = PKGCONFIG_NO_THANKS
