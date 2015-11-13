# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	units
PORTVERSION=	2.6.4
PORTREVISION=	5
CATEGORIES=	lang
PKGNAMEPREFIX=	fpc-

MAINTAINER=	freebsd-fpc@FreeBSD.org
COMMENT=	Meta port to install Free Pascal units

ONLY_FOR_ARCHS=	i386 amd64
USES=		metaport

BUILDNAME=	${ARCH}-freebsd

OPTIONS_DEFINE=	A52 ASPELL BFD BZIP2 CAIRO CHM DBUS DBLIB DTS FASTCGI FCL-ASYNC FCL-BASE \
		FCL-EXTRA FCL-DB FCL-FPCUNIT FCL-IMAGE FCL-JS FCL-JSON FCL-NET FCL-PASSRC \
		FCL-PROCESS FCL-REGISTRY FCL-RES FCL-WEB FCL-XML FFTW FPINDEXER \
		FPMKUNIT FPPKG FV GDBM GMP GTK2 HERMES ICONVENC \
		IMAGEMAGICK LDAP LIBCURL LIBGD LIBPNG LIBVLC LIBXML2 LUA MAD MATROSKA \
		MODPLUG NCURSES NEWT NUMLIB OGGVORBIS OPENAL OPENGL OPENSSL PCAP PROJ4 \
		PXLIB RSVG REXX SDL SNDFILE SVGALIB SYMBOLIC SYSLOG TCL UNZIP USERS \
		UTMP UUID X11 XFORMS ZLIB

A52_DESC=	Interface to a52 library
ASPELL_DESC=	Interface to aspell spelling checker
BFD_DESC=	Interface to GNU Binary Format description
BZIP2_DESC=	Free Pascal bzip2 unit
CAIRO_DESC=	Interface to cairo library
CHM_DESC=	Free Pbscal unit to manipulate chm files
DBUS_DESC=	Interface to dbus library
DBLIB_DESC=	Interface to dblib library
DTS_DESC=	Interface to dts library
FASTCGI_DESC=	Free Pascal fastcgi unit
FCL_ASYNC_DESC=	Free Pascal interface to async library
FCL_BASE_DESC=	Free Pascal Component Library (base)
FCL_DB_DESC=	Free Pascal Component Library (db)
FCL_EXTRA_DESC=	Free Pascal Component Library (extra)
FCL_FPCUNIT_DESC=	Free Pascal Component Library (fpcunit)
FCL_IMAGE_DESC=	Free Pascal Component Library (image)
FCL_JS_DESC=	Free Pascal implementation of (js)
FCL_JSON_DESC=	Free Pascal implementation of (json)
FCL_NET_DESC=	Free Pascal Component Library (net)
FCL_PASSRC_DESC=	Free Pascal Component Library (passrc)
FCL_PROCESS_DESC=	Unit to start and manipulate other programs
FCL_REGISTRY_DESC=	Free Pascal Component Library (registry)
FCL_RES_DESC=	Free Pascal Component Library (res)
FCL_WEB_DESC=	Free Pascal Component Library (web)
FCL_XML_DESC=	Free Pascal Component Library (xml)
FFTW_DESC=	Interface to the FFTW3 library
FPPKG_DESC=	Free Pascal package unit
FPMKUNIT_DESC=	Free Pascal build system unit
FV_DESC=	Free Pascal unit for Delphi support
GDBM_DESC=	Interface to the GNU database system
GMP_DESC=	Interface to gmp library
GTK2_DESC=	Interface to gtk2 libraries
HERMES_DESC=	Free Pascal hermes unit
ICONVENC_DESC=	Interface to iconv library
FPINDEXER_DESC=	Database indexer with database/flat file backend
IMAGEMAGICK_DESC=	Interface to ImageMagick
LDAP_DESC=	Interface to OpenLDAP
LIBCURL_DESC=	Interface to curl library
LIBGD_DESC=	Interface to gd library
LIBPNG_DESC=	Interface to png library
LIBVLC_DESC=	Free Pascal vlc unit
LIBXML2_DESC=	Interface to libxml2 library
LUA_DESC=	Interface to lua interpreter
MAD_DESC=	Interface to mad library
MATROSKA_DESC=	Interface to matroska library
MODPLUG_DESC=	Interface to modplug library
NCURSES_DESC=	Interface to ncurses library
NEWT_DESC=	Interface to newt library
NUMLIB_DESC=	Free Pascal unit for numerical methods
OGGVORBIS_DESC=	Interaface to ogg & vorbis libraries
OPENAL_DESC=	Interface to openal library
OPENGL_DESC=	Interface to opengl library
OPENSSL_DESC=	Interface to openssl library
PCAP_DESC=	Interface to pcap library
PROJ4_DESC=	Interface to proj library
PXLIB_DESC=	Unit to read various Paradox file
REXX_DESC=	Intrface to rexx-regina library
RSVG_DESC=	Interface to rsvg2 library
SDL_DESC=	Free Pascal interface to SDL library
SNDFILE_DESC=	Interface to sndfile library
SVGALIB_DESC=	Interface to svgalib library
SYMBOLIC_DESC=	Simple expression parsing and evaluating
SYSLOG_DESC=	Interface to system logger
TCL_DESC=	Interface to tcl/tk interpreter
UNZIP_DESC=	Routines for unzipping zip files
USERS_DESC=	Interface to manipulate users
UTMP_DESC=	Gather information from the utmp file
UUID_DESC=	Free Pascal uuid unit
X11_DESC=	Interface to X windows server
XFORMS_DESC=	Interface to X-Forms
ZLIB_DESC=	Interface to the zlib compression library

OPTIONS_DEFAULT=A52 ASPELL BZIP2 CAIRO CHM DBUS DBLIB DTS FASTCGI FCL-ASYNC FCL-BASE \
		FCL-EXTRA FCL-DB FCL-FPCUNIT FCL-IMAGE FCL-JS FCL-JSON FCL-NET FCL-PASSRC \
		FCL-PROCESS FCL-REGISTRY FCL-RES FCL-WEB FCL-XML FFTW FPINDEXER \
		FPMKUNIT FPPKG FV GDBM GMP GTK2 HERMES ICONVENC \
		IMAGEMAGICK LDAP LIBCURL LIBGD LIBPNG LIBVLC LIBXML2 LUA MAD MATROSKA \
		MODPLUG NCURSES NEWT NUMLIB OGGVORBIS OPENAL OPENGL OPENSSL PCAP PROJ4 \
		PXLIB RSVG REXX SDL SNDFILE SVGALIB SYMBOLIC SYSLOG TCL UNZIP USERS \
		UTMP UUID X11 XFORMS ZLIB

.if !exists(/usr/include/lwres)	# directory only exists on FreeBSD 9
# On FreeBSD 9, CAIRO is built with GCC which pulls in binutils
# binutils and BFD conflict, so BFD and CAIRO cannot coexist of F9
OPTIONS_DEFAULT+=	BFD
.endif

.include <bsd.port.options.mk>

UNITS_SELECTED=		#
.for OPT in ${OPTIONS_DEFINE}
.	if ${PORT_OPTIONS:M${OPT}}
UNITS_SELECTED+=	${OPT:tl}
.	endif
.endfor

USE_FPC_RUN=	yes
USE_FPC=	${UNITS_SELECTED}

.include <bsd.port.mk>
