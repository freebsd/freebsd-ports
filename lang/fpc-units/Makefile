# New ports collection makefile for:	fpc-units
# Date created:		2006-06-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	units
PORTVERSION=	2.0.2
PORTREVISION=	1
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
		FCL	"Free Pascal Component Library"	on \
		FORMS	"Interface to X-Forms"	on \
		FPGTK	"Interface to create programs with gtk"	on \
		FV	"Free Pascal unit for Delphi support" on \
		GCONF	"Interface to GConf" on \
		GDBM	"Interface to the GNU database system"	on \
		GGI	"Interface to libggi library"	on \
		GNOME	"Free Pascal unit to create programs for GNOME" on \
		GTK	"Interface to gtk libraries"	on \
		GTK2	"Interface to gtk2 libraries"	on \
		IMLIB	"Interface to imlib library"	on \
		LIBGD	"Interface to gd library"	on \
		LIBPNG	"Interface to png library"	on \
		NCURSES	"Interface to ncurses library"	on \
		OPENGL	"Interface to opengl library"	on \
		SVGALIB	"Interface to svgalib library"	on \
		SYSLOG	"Interface to system logger"	on \
		TCL	"Interface to tcl/tk interpreter"	on \
		UNZIP	"Routines for unzipping zip files"	on \
		UTMP	"Interface to gather information from the utmp file"	on \
		X11	"Interface to X windows server"	on \
		ZLIB	"Interface to the zlib compression library"	on \
		ZVT	"Interface to Zed's Virtual Terminal"	on

.include <bsd.port.pre.mk>

UNITSDIR=	${LOCALBASE}/lib/fpc/${PORTVERSION}/units/${BUILDNAME}
ALL_OPTIONS=	BFD FCL FORMS FPGTK FV GCONF GDBM GGI GNOME GTK GTK2 \
		IMLIB LIBGD LIBPNG NCURSES OPENGL SVGALIB \
		SYSLOG TCL UNZIP UTMP X11 ZLIB ZVT

BFD_UNIT=	devel/fpc-bfd
FCL_UNIT=	devel/fpc-fcl
FORMS_UNIT=	x11-toolkits/fpc-forms
FPGTK_UNIT=	graphics/fpc-fpgtk
FV_UNIT=	devel/fpc-fv
GCONF_UNIT=	devel/fpc-gconf
GDBM_UNIT=	databases/fpc-gdbm
GGI_UNIT=	graphics/fpc-ggi
GNOME_UNIT=	x11-toolkits/fpc-gnome
GTK_UNIT=	x11-toolkits/fpc-gtk
GTK2_UNIT=	x11-toolkits/fpc-gtk2
IMLIB_UNIT=	graphics/fpc-imlib
LIBGD_UNIT=	graphics/fpc-libgd
LIBPNG_UNIT=	graphics/fpc-libpng
NCURSES_UNIT=	graphics/fpc-ncurses
OPENGL_UNIT=	graphics/fpc-opengl
SVGALIB_UNIT=	graphics/fpc-svgalib
SYSLOG_UNIT=	sysutils/fpc-syslog
TCL_UNIT=	lang/fpc-tcl
UNZIP_UNIT=	archivers/fpc-unzip
UTMP_UNIT=	sysutils/fpc-utmp
X11_UNIT=	x11/fpc-x11
ZLIB_UNIT=	devel/fpc-zlib
ZVT_UNIT=	x11-toolkits/fpc-zvt

.for OPT in ${ALL_OPTIONS}
.	if defined(WITH_${OPT})  && !defined(WITHOUT_${OPT})
RUN_DEPENDS+=	${UNITSDIR}/${OPT:L}/Package.fpc:${PORTSDIR}/${${OPT}_UNIT}
.	endif
.endfor

do-install: build
	@${DO_NADA}

.include <bsd.port.post.mk>
