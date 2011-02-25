# New ports collection makefile for:	fpc-units
# Date created:		2006-06-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	units
PORTVERSION=	2.4.2
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	# none
PKGNAMEPREFIX=	fpc-
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A meta port to install Free Pascal units

ONLY_FOR_ARCHS=	i386 amd64
NO_BUILD=	yes

BUILDNAME=	${ARCH}-freebsd

OPTIONS=	A52	"Interface to a52 library"	on \
		ASPELL "Interface to aspell spelling checker"	on \
		BFD	"Interface to GNU Binary Format description"	on \
		BZIP2	"Free Pascal bzip2 unit"	on \
		CAIRO	"Interface to cairo library" on \
		CHM	"Free Pbscal unit to manipulate chm files" on \
		DBUS	"Interface to dbus library"	on \
		DTS	"Interface to dts library"	on \
		FASTCGI	"Free Pascal fastcgi unit" on \
		FCL_ASYNC "Free Pascal interface to async library" on \
		FCL_BASE	"Free Pascal Component Library (base)"	on \
		FCL_DB	"Free Pascal Component Library (db)"	on \
		FCL_FPCUNIT	"Free Pascal Component Library (fpcunit)"	on \
		FCL_IMAGE	"Free Pascal Component Library (image)"	on \
		FCL_JSON	"Free Pascal implementation of JSON"	on \
		FCL_NET	"Free Pascal Component Library (net)"	on \
		FCL_PASSRC	"Free Pascal Component Library (passrc)"	on \
		FCL_PROCESS	"Unit to start and manipulate other programs"	on \
		FCL_REGISTRY	"Free Pascal Component Library (registry)"	on \
		FCL_RES	"Free Pascal Component Library (res)"	on \
		FCL_WEB	"Free Pascal Component Library (web)"	on \
		FCL_XML	"Free Pascal Component Library (xml)"	on \
		FFTW	"Interface to the FFTW3 library" on \
		FPGTK	"Interface to create programs with gtk"	on \
		FPMKUNIT "Free Pascal build system unit" on \
		FPVECTORIAL	"Free Pascal fpvectorial unit"	on \
		FV	"Free Pascal unit for Delphi support" on \
		GDBM	"Interface to the GNU database system"	on \
		GGI	"Interface to libggi library"	on \
		GMP	"Interface to gmp library"	on \
		GNOME1	"Interface to create programs for GNOME" on \
		GTK1	"Interface to gtk libraries"	on \
		GTK2	"Interface to gtk2 libraries"	on \
		HERMES	"Free Pascal hermes unit"	on \
		ICONVENC	"Interface to iconv library"	on \
		IMAGEMAGICK	"Interface to ImageMagick"	on \
		IMLIB	"Interface to imlib library"	on \
		LDAP	"Interface to OpenLDAP"	on \
		LIBCURL	"Interface to curl library"	on \
		LIBGD	"Interface to gd library"	on \
		LIBPNG	"Interface to png library"	on \
		LIBXML2	"Interface to libxml2 library"	on \
		LUA	"Interface to lua interpreter"	on \
		MAD	"Interface to mad library" on \
		MATROSKA	"Interface to matroska library" on \
		MODPLUG	"Interface to modplug library"	on \
		NCURSES	"Interface to ncurses library"	on \
		NEWT	"Interface to newt library"	on \
		NUMLIB	"Free Pascal unit for numerical methods"	on \
		OGGVORBIS	"Interaface to ogg & vorbis libraries"	on \
		OPENAL	"Interface to openal library"	on \
		OPENGL	"Interface to opengl library"	on \
		OPENSSL	"Interface to openssl library"	on \
		PCAP	"Interface to pcap library"	on \
		PROJ4	"Interface to proj library"	on \
		PXLIB	"Unit to read various Paradox file"	on \
		REXX	"Intrface to rexx-regina library"	on \
		RSVG	"Interface to rsvg2 library"	on \
		SDL	"Free Pascal interface to SDL library"	on \
		SNDFILE	"Interface to sndfile library"	on \
		SVGALIB	"Interface to svgalib library"	on \
		SYMBOLIC	"Simple expression parsing and evaluating"	on \
		SYSLOG	"Interface to system logger"	on \
		TCL	"Interface to tcl/tk interpreter"	on \
		UNZIP	"Routines for unzipping zip files"	on \
		USERS	"Interface to manipulate users"	on \
		UTMP	"Gather information from the utmp file"	on \
		UUID	"Free Pascal uuid unit"	on \
		X11	"Interface to X windows server"	on \
		XFORMS	"Interface to X-Forms"	on \
		ZLIB	"Interface to the zlib compression library"	on \

PORT_DBDIR?=	/var/db/ports
LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}
OPTIONSFILE?=	${PORT_DBDIR}/${LATEST_LINK}/options
                
.if exists(${OPTIONSFILE})
.include "${OPTIONSFILE}"
.endif

ALL_OPTIONS=	A52 ASPELL BFD BZIP2 CAIRO CHM DBUS DTS FASTCGI FCL-ASYNC FCL-BASE \
		FCL-DB FCL-FPCUNIT FCL-IMAGE FCL-JSON FCL-NET FCL-PASSRC FCL-PROCESS \
		FCL-REGISTRY FCL-RES FCL-WEB FCL-XML FFTW FPGTK FPMKUNIT FPVECTORIAL \
		FV GDBM GGI GMP GNOME1 GTK1 GTK2 HERMES ICONVENC IMAGEMAGICK IMLIB \
		LDAP LIBCURL LIBGD LIBPNG LIBXML2 LUA MAD MATROSKA MODPLUG NCURSES \
		NEWT NUMLIB OGGVORBIS OPENAL OPENGL OPENSSL PCAP PROJ4 PXLIB RSVG \
		REXX SDL SNDFILE SVGALIB SYMBOLIC SYSLOG TCL UNZIP USERS UTMP UUID \
		X11 XFORMS ZLIB

UNITS_SELECTED=		#
.for OPT in ${ALL_OPTIONS}
.	if defined(WITH_${OPT}) || !defined(WITHOUT_${OPT})
UNITS_SELECTED+=	${OPT:L}
.	endif
.endfor
USE_FPC=	${UNITS_SELECTED}

do-install: build
	@${DO_NADA}

.include <bsd.port.mk>
