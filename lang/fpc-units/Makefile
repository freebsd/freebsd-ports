# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	units
PORTVERSION=	3.0.0
CATEGORIES=	lang
PKGNAMEPREFIX=	fpc-

MAINTAINER=	freebsd-fpc@FreeBSD.org
COMMENT=	Meta port to install Free Pascal units

ONLY_FOR_ARCHS=	i386 amd64
USES=		metaport

BUILDNAME=	${ARCH}-${OPSYS:tl}

ALL_OPTIONS=	A52 ASPELL BZIP2 CAIRO CHM DBLIB DBUS DTS FASTCGI \
		FCL_ASYNC FCL_BASE FCL_DB FCL_EXTRA FCL_FPCUNIT FCL_IMAGE \
		FCL_JS FCL_JSON FCL_NET FCL_PASSRC FCL_REGISTRY FCL_RES \
		FCL_SDO FCL_SOUND FCL_STL FCL_WEB FCL_XML FFTW \
		FPINDEXER FPPKG FV GDBM GMP GTK2 HERMES ICONVENC \
		IMAGEMAGICK LDAP LIBCURL LIBGD LIBPNG LIBXML2 LIBVLC LUA MAD \
		MODPLUG NCURSES NEWT NUMLIB OGGVORBIS OPENAL OPENGL \
		OPENSSL PASJPEG PCAP PROJ4 PXLIB RSVG REXX RTL_CONSOLE \
		RTL_EXTRA RTL_OBJPAS RTL_UNICODE SDL SVGALIB SYMBOLIC \
		SYSLOG TCL UNZIP USERS UTMP UUID X11 XFORMS ZLIB

OPTIONS_DEFINE:=	${ALL_OPTIONS} BFD
OPTIONS_DEFAULT:=	${ALL_OPTIONS}

A52_DESC=		Interface to a52 library
ASPELL_DESC=		Interface to aspell spelling checker
BFD_DESC=		Interface to GNU Binary Format description
BZIP2_DESC=		Unit for bzip2
CAIRO_DESC=		Interface to cairo library
CHM_DESC=		Unit to manipulate chm files
DBLIB_DESC=		Interface to dblib library
DBUS_DESC=		Interface to dbus library
DTS_DESC=		Interface to dts library
FASTCGI_DESC=		Unit for fastcgi
FCL_ASYNC_DESC=		Component Library (async)
FCL_BASE_DESC=		Component Library (base)
FCL_DB_DESC=		Component Library (db)
FCL_EXTRA_DESC=		Component Library (extra)
FCL_FPCUNIT_DESC=	Component Library (fpcunit)
FCL_IMAGE_DESC=		Component Library (image)
FCL_JS_DESC=		Component Library (js)
FCL_JSON_DESC=		Component Library (json)
FCL_NET_DESC=		Component Library (net)
FCL_PASSRC_DESC=	Component Library (passrc)
FCL_REGISTRY_DESC=	Component Library (registry)
FCL_RES_DESC=		Component Library (res)
FCL_SDO_DESC=		Component Library (sdo)
FCL_SOUND_DESC=		Component Library (sound)
FCL_STL_DESC=		Component Library (stl)
FCL_WEB_DESC=		Component Library (web)
FCL_XML_DESC=		Component Library (xml)
FFTW_DESC=		Interface to the FFTW3 library
FPINDEXER_DESC=		Database indexer
FPPKG_DESC=		Unit for packaging
FV_DESC=		Unit for Delphi support
GDBM_DESC=		Interface to the GNU database system
GMP_DESC=		Interface to gmp library
GTK2_DESC=		Interface to gtk2 libraries
HERMES_DESC=		Unit for hermes
ICONVENC_DESC=		Interface to iconv library
IMAGEMAGICK_DESC=	Interface to ImageMagick
LDAP_DESC=		Interface to OpenLDAP
LIBCURL_DESC=		Interface to curl library
LIBGD_DESC=		Interface to gd library
LIBPNG_DESC=		Interface to png library
LIBVLC_DESC=		Unit for VLC
LIBXML2_DESC=		Interface to libxml2 library
LUA_DESC=		Interface to lua interpreter
MAD_DESC=		Interface to mad library
MODPLUG_DESC=		Interface to modplug library
NCURSES_DESC=		Interface to ncurses library
NEWT_DESC=		Interface to newt library
NUMLIB_DESC=		Unit for numerical methods
OGGVORBIS_DESC=		Interaface to ogg & vorbis libraries
OPENAL_DESC=		Interface to openal library
OPENGL_DESC=		Interface to opengl library
OPENSSL_DESC=		Interface to openssl library
PASJPEG_DESC=		Unit for JPEG image format handling
PCAP_DESC=		Interface to pcap library
PROJ4_DESC=		Interface to proj library
PXLIB_DESC=		Unit to read various Paradox file
REXX_DESC=		Interface to rexx-regina library
RSVG_DESC=		Interface to rsvg2 library
RTL_CONSOLE_DESC=	Run-Time lib for console abstraction
RTL_EXTRA_DESC=		Run-Time lib not needed for bootstrapping
RTL_OBJPAS_DESC=	Rtl-objpas, aux. Delphi compat unit
RTL_UNICODE_DESC=	Rtl-unicode, misc Unicode units
SDL_DESC=		Interface to SDL library
SVGALIB_DESC=		Interface to svgalib library
SYMBOLIC_DESC=		Simple expression parsing and evaluating
SYSLOG_DESC=		Interface to system logger
TCL_DESC=		Interface to tcl/tk interpreter
UNZIP_DESC=		Routines for unzipping zip files
USERS_DESC=		Interface to manipulate users
UTMP_DESC=		Gather information from the utmp file
UUID_DESC=		Unit for UUID
X11_DESC=		Interface to X windows server
XFORMS_DESC=		Interface to X-Forms
ZLIB_DESC=		Interface to the zlib compression library

.if !exists(/usr/include/lwres)	# directory only exists on FreeBSD 9
# On FreeBSD 9, CAIRO is built with GCC which pulls in binutils
# binutils and BFD conflict, so BFD and CAIRO cannot coexist on F9
OPTIONS_DEFAULT+=	BFD
.endif

.include <bsd.port.options.mk>

UNITS_SELECTED=
.for OPT in ${OPTIONS_DEFINE}
.	if ${PORT_OPTIONS:M${OPT}}
UNITS_SELECTED+=	${OPT:tl:S/rtl_/rtl-/:S/fcl_/fcl-/}
.	endif
.endfor

USE_FPC_RUN=	yes
USE_FPC=	${UNITS_SELECTED}

.include <bsd.port.mk>
