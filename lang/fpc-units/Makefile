# New ports collection makefile for:	fpc-units
# Date created:		2006-06-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	units
PORTVERSION=	2.2.4
CATEGORIES=	lang
MASTER_SITES=	# none
PKGNAMEPREFIX=	fpc-
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A meta port to install Free Pascal units

ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes

BUILDNAME=	${ARCH}-freebsd

OPTIONS=	ASPELL "Interface to aspell spelling checker"	on \
		BFD	"Interface to GNU Binary Format description"	on \
		CAIRO	"Interface to cairo library" on \
		CHM	"Free Pbscal unit to manipulate chm files" on \
		FCL_ASYNC "Free Pascal interface to async library" on \
		FCL_BASE	"Free Pascal Component Library (base)"	on \
		FCL_DB	"Free Pascal Component Library (db)"	on \
		FCL_FPCUNIT	"Free Pascal Component Library (fpcunit)"	on \
		FCL_IMAGE	"Free Pascal Component Library (image)"	on \
		FCL_JSON	"Free Pascal implementation of JSON"	on \
		FCL_NET	"Free Pascal Component Library (net)"	on \
		FCL_PASSRC	"Free Pascal Component Library (passrc)"	on \
		FCL_PROCESS	"Free Pascal unit to start and manipulate other programs"	on \
		FCL_REGISTRY	"Free Pascal Component Library (registry)"	on \
		FCL_WEB	"Free Pascal Component Library (web)"	on \
		FCL_XML	"Free Pascal Component Library (xml)"	on \
		FFTW	"Interface to the FFTW3 library" on \
		FPMKUNIT "Free Pascal build system unit" on \
		FPGTK	"Interface to create programs with gtk"	on \
		FV	"Free Pascal unit for Delphi support" on \
		GDBM	"Interface to the GNU database system"	on \
		GGI	"Interface to libggi library"	on \
		GNOME1	"Free Pascal unit to create programs for GNOME" on \
		GTK1	"Interface to gtk libraries"	on \
		GTK2	"Interface to gtk2 libraries"	on \
		ICONVENC	"Free Pascal interface to iconv library"	on \
		IMAGEMAGICK	"Free Pascal interface to ImageMagick"	on \
		IMLIB	"Interface to imlib library"	on \
		LIBCURL	"Interface to curl library"	on \
		LIBGD	"Interface to gd library"	on \
		LIBPNG	"Interface to png library"	on \
		NCURSES	"Interface to ncurses library"	on \
		NUMLIB	"Free Pascal unit for numerical methods"	on \
		OPENGL	"Interface to opengl library"	on \
		OPENSSL	"Interface to openssl library"	on \
		PCAP	"Interface to pcap library"	on \
		PXLIB	"Free Pascal unit to read various Paradox file"	on \
		SDL	"Free Pascal interface to SDL library"	on \
		SVGALIB	"Interface to svgalib library"	on \
		SYMBOLIC	"FreePascal unit to simple expression parsing and evaluating"	on \
		SYSLOG	"Interface to system logger"	on \
		TCL	"Interface to tcl/tk interpreter"	on \
		UNZIP	"Routines for unzipping zip files"	on \
		USERS	"Free Pascal interfaces to manipulate users"	on \
		UTMP	"Interface to gather information from the utmp file"	on \
		X11	"Interface to X windows server"	on \
		XFORMS	"Interface to X-Forms"	on \
		ZLIB	"Interface to the zlib compression library"	on \

PORT_DBDIR?=	/var/db/ports
LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}
OPTIONSFILE?=	${PORT_DBDIR}/${LATEST_LINK}/options
                
.if exists(${OPTIONSFILE})
.include "${OPTIONSFILE}"
.endif

ALL_OPTIONS=	ASPELL BFD CAIRO CHM FCL-ASYNC FCL-BASE FCL-DB FCL-FPCUNIT FCL-IMAGE \
		FCL-JSON FCL-NET FCL-PASSRC FCL-PROCESS FCL-REGISTRY FCL-WEB FCL-XML \
		FFTW FPMKUNIT FPGTK FV GDBM GGI GNOME1 GTK1 GTK2 ICONVENC IMAGEMAGICK IMLIB LIBCURL \
		LIBGD LIBPNG NCURSES NUMLIB OPENGL OPENSSL PCAP PXLIB SDL SVGALIB SYMBOLIC \
		SYSLOG TCL UNZIP USERS UTMP X11 XFORMS ZLIB

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
