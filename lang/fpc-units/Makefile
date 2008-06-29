# New ports collection makefile for:	fpc-units
# Date created:		2006-06-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	units
PORTVERSION=	2.2.0
PORTREVISION=	2
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

OPTIONS=	BFD	"Interface to GNU Binary Format description"	on \
		CAIRO	"Interface to cairo library" on \
		FCL_BASE	"Free Pascal Component Library (base)"	on \
		FCL_DB	"Free Pascal Component Library (db)"	on \
		FCL_FPCUNIT	"Free Pascal Component Library (fpcunit)"	on \
		FCL_IMAGE	"Free Pascal Component Library (image)"	on \
		FCL_NET	"Free Pascal Component Library (net)"	on \
		FCL_PASSRC	"Free Pascal Component Library (passrc)"	on \
		FCL_REGISTRY	"Free Pascal Component Library (registry)"	on \
		FCL_WEB	"Free Pascal Component Library (web)"	on \
		FCL_XML	"Free Pascal Component Library (xml)"	on \
		FFTW	"Interface to the FFTW3 library" on \
		FPMKUNIT "Free Pascal build system unit" on \
		FORMS	"Interface to X-Forms"	on \
		FPGTK	"Interface to create programs with gtk"	on \
		FV	"Free Pascal unit for Delphi support" on \
		GCONF	"Interface to GConf" on \
		GDBM	"Interface to the GNU database system"	on \
		GGI	"Interface to libggi library"	on \
		GNOME	"Free Pascal unit to create programs for GNOME" on \
		GTK	"Interface to gtk libraries"	on \
		GTK2	"Interface to gtk2 libraries"	on \
		HTTPD	"Free Pascal httpd unit" on \
		IMLIB	"Interface to imlib library"	on \
		LIBCURL	"Interface to curl library"	on \
		LIBGD	"Interface to gd library"	on \
		LIBPNG	"Interface to png library"	on \
		NCURSES	"Interface to ncurses library"	on \
		OPENGL	"Interface to opengl library"	on \
		OPENSSL	"Interface to openssl library"	on \
		PCAP	"Interface to pcap library"	on \
		SVGALIB	"Interface to svgalib library"	on \
		SYSLOG	"Interface to system logger"	on \
		TCL	"Interface to tcl/tk interpreter"	on \
		UNZIP	"Routines for unzipping zip files"	on \
		UTMP	"Interface to gather information from the utmp file"	on \
		X11	"Interface to X windows server"	on \
		ZLIB	"Interface to the zlib compression library"	on \
		ZVT	"Interface to Zed's Virtual Terminal"	on

PORT_DBDIR?=	/var/db/ports
LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}
OPTIONSFILE?=	${PORT_DBDIR}/${LATEST_LINK}/options
                
.if exists(${OPTIONSFILE})
.include "${OPTIONSFILE}"
.endif

ALL_OPTIONS=	BFD CAIRO FCL-BASE FCL-DB FCL-FPCUNIT FCL-IMAGE FCL-NET FCL-PASSRC \
		FCL-REGISTRY FCL-WEB FCL-XML FFTW FPMKUNIT FORMS FPGTK FV GCONF GDBM \
		GGI GNOME GTK GTK2 HTTPD IMLIB LIBCURL LIBGD LIBPNG NCURSES OPENGL \
		OPENSSL PCAP SVGALIB SYSLOG TCL UNZIP UTMP X11 ZLIB ZVT

UNITS_SELECTED=		#
.for OPT in ${ALL_OPTIONS}
.	if defined(WITH_${OPT})  && !defined(WITHOUT_${OPT})
UNITS_SELECTED+=	${OPT:L}
.	endif
.endfor
USE_FPC=	${UNITS_SELECTED}

do-install: build
	@${DO_NADA}

.include <bsd.port.mk>
