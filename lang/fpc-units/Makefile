PORTNAME=	units
PORTVERSION=	3.2.0
PORTREVISION=	1
CATEGORIES=	lang
PKGNAMEPREFIX=	fpc-

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Meta port to install Free Pascal units

ONLY_FOR_ARCHS=	i386 amd64
USES=		fpc:run metaport

BUILDNAME=	${ARCH}-${OPSYS:tl}

ALL_OPTIONS=	A52 ASPELL BFD BZIP2 CAIRO CHM DBLIB DBUS DTS FASTCGI \
		FCL_ASYNC FCL_BASE FCL_DB FCL_EXTRA FCL_FPCUNIT FCL_IMAGE \
		FCL_JS FCL_JSON FCL_NET FCL_PASSRC FCL_PDF FCL_REGISTRY \
		FCL_REPORT FCL_RES FCL_SDO FCL_SOUND FCL_STL FCL_WEB FCL_XML \
		FFTW FPINDEXER FPPKG FV GDBM GNUTLS GMP GOOGLEAPI \
		GTK2 HERMES ICONVENC IMAGEMAGICK LDAP LIBCUPS LIBCURL LIBENET \
		LIBFONTCONFIG LIBGD LIBMAGIC LIBMICROHTTPD LIBPNG LIBXML2 \
		LIBVLC LUA MAD MODPLUG NCURSES NEWT NUMLIB ODATA OGGVORBIS \
		OPENAL OPENGL OPENSSL PASJPEG PASTOJS PCAP PROJ4 PXLIB RSVG \
		REXX RTL_CONSOLE RTL_EXTRA RTL-GENERICS RTL_OBJPAS RTL_UNICODE \
		SDL SVGALIB SYMBOLIC SYSLOG UNZIP USERS UTMP UUID VCL-COMPAT \
		WEBIDL X11 XFORMS ZLIB

OPTIONS_DEFINE:=	${ALL_OPTIONS}
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
FCL_PDF_DESC=		Component Library (pdf)
FCL_REGISTRY_DESC=	Component Library (registry)
FCL_REPORT_DESC=		Freepascal report unit
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
GOOGLEAPI_DESC=		Interface to the google api
GMP_DESC=		Interface to gmp library
GNUTLS_DESC=		Unit for GnuTLS
GTK2_DESC=		Interface to gtk2 libraries
HERMES_DESC=		Unit for hermes
ICONVENC_DESC=		Interface to iconv library
IMAGEMAGICK_DESC=	Interface to ImageMagick
LDAP_DESC=		Interface to OpenLDAP
LIBCUPS_DESC=		Interface to cups
LIBCURL_DESC=		Interface to curl library
LIBENET_DESC=		Interface to enet library
LIBFONTCONFIG_DESC=	Interface to fontconfig library
LIBGD_DESC=		Interface to gd library
LIBMAGIC_DESC=		Interface to magic library
LIBMICROHTTPD_DESC=	Interface to libmicrohttpd library
LIBPNG_DESC=		Interface to png library
LIBVLC_DESC=		Unit for VLC
LIBXML2_DESC=		Interface to libxml2 library
LUA_DESC=		Interface to lua interpreter
MAD_DESC=		Interface to mad library
MODPLUG_DESC=		Interface to modplug library
NCURSES_DESC=		Interface to ncurses library
NEWT_DESC=		Interface to newt library
NUMLIB_DESC=		Unit for numerical methods
ODATA_DESC=		Unit for odata protocol
OGGVORBIS_DESC=		Interaface to ogg & vorbis libraries
OPENAL_DESC=		Interface to openal library
OPENGL_DESC=		Interface to opengl library
OPENSSL_DESC=		Interface to openssl library
PASJPEG_DESC=		Unit for JPEG image format handling
PASTOJS_DESC=		Interface to pas2js library
PCAP_DESC=		Interface to pcap library
PROJ4_DESC=		Interface to proj library
PXLIB_DESC=		Unit to read various Paradox file
REXX_DESC=		Interface to rexx-regina library
RSVG_DESC=		Interface to rsvg2 library
RTL_CONSOLE_DESC=	Run-Time lib for console abstraction
RTL_EXTRA_DESC=		Run-Time lib not needed for bootstrapping
RTL-GENERICS_DESC=	Run-Time lib for generic containers
RTL_OBJPAS_DESC=	Rtl-objpas, aux. Delphi compat unit
RTL_UNICODE_DESC=	Rtl-unicode, misc Unicode units
SDL_DESC=		Interface to SDL library
SVGALIB_DESC=		Interface to svgalib library
SYMBOLIC_DESC=		Simple expression parsing and evaluating
SYSLOG_DESC=		Interface to system logger
UNZIP_DESC=		Routines for unzipping zip files
USERS_DESC=		Interface to manipulate users
UTMP_DESC=		Gather information from the utmp file
UUID_DESC=		Unit for UUID
VCL-COMPAT_DESC=	Interface to visual component library
X11_DESC=		Interface to X windows server
XFORMS_DESC=		Interface to X-Forms
WEBIDL_DESC=		Interface to webidl
ZLIB_DESC=		Interface to the zlib compression library

.include <bsd.port.options.mk>

UNITS_SELECTED=
.for OPT in ${OPTIONS_DEFINE}
.	if ${PORT_OPTIONS:M${OPT}}
UNITS_SELECTED+=	${OPT:tl:S/rtl_/rtl-/:S/fcl_/fcl-/}
.	endif
.endfor

USE_FPC=	${UNITS_SELECTED}

.include <bsd.port.mk>
