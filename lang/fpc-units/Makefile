# New ports collection makefile for:	fpc-units
# Date created:		2006-06-05
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	units
PORTVERSION=	2.2.0
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

.include <bsd.port.pre.mk>

UNITSDIR=	${LOCALBASE}/lib/fpc/${PORTVERSION}/units/${BUILDNAME}
ALL_OPTIONS=	BFD CAIRO FCL-BASE FCL-DB FCL-FPCUNIT FCL-IMAGE FCL-NET FCL-PASSRC \
		FCL-REGISTRY FCL-WEB FCL-XML FFTW FPMKUNIT FORMS FPGTK FV GCONF GDBM \
		GGI GNOME GTK GTK2 HTTPD IMLIB LIBCURL LIBGD LIBPNG NCURSES OPENGL \
		OPENSSL PCAP SVGALIB SYSLOG TCL UNZIP UTMP X11 ZLIB ZVT

BFD_UNIT=	devel/fpc-bfd
CAIRO_UNIT=	graphics/fpc-cairo
FCL_BASE_UNIT=	devel/fpc-fcl-base
FCL_DB_UNIT=	devel/fpc-fcl-db
FCL_FPCUNIT_UNIT=	devel/fpc-fcl-fpcunit
FCL_IMAGE_UNIT=	devel/fpc-fcl-image
FCL_NET_UNIT=	devel/fpc-fcl-net
FCL_PASSRC_UNIT=	devel/fpc-fcl-passrc
FCL_REGISTRY_UNIT=	devel/fpc-fcl-registry
FCL_WEB_UNIT=	devel/fpc-fcl-web
FCL_XML_UNIT=	devel/fpc-fcl-xml
FFTW_UNIT=	math/fpc-fftw
FPMKUNIT_UNIT=	devel/fpc-fpmkunit
FORMS_UNIT=	x11-toolkits/fpc-forms
FPGTK_UNIT=	graphics/fpc-fpgtk
FV_UNIT=	devel/fpc-fv
GCONF_UNIT=	devel/fpc-gconf
GDBM_UNIT=	databases/fpc-gdbm
GGI_UNIT=	graphics/fpc-ggi
GNOME_UNIT=	x11-toolkits/fpc-gnome
GTK_UNIT=	x11-toolkits/fpc-gtk
GTK2_UNIT=	x11-toolkits/fpc-gtk2
HTTPD_UNIT=	www/fpc-httpd
IMLIB_UNIT=	graphics/fpc-imlib
LIBCURL_UNIT=	ftp/fpc-libcurl
LIBGD_UNIT=	graphics/fpc-libgd
LIBPNG_UNIT=	graphics/fpc-libpng
NCURSES_UNIT=	graphics/fpc-ncurses
OPENGL_UNIT=	graphics/fpc-opengl
OPENSSL_UNIT=	security/fpc-openssl
PCAP_UNIT=	net/fpc-pcap
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
RUN_DEPENDS+=	${UNITSDIR}/${OPT:L:S/httpd/httpd-1.3/}/Package.fpc:${PORTSDIR}/${${OPT:S/-/_/}_UNIT}
.	endif
.endfor

do-install: build
	@${DO_NADA}

.include <bsd.port.post.mk>
