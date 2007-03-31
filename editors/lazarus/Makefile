# New ports collection makefile for:	lazarus
# Date Created:				2006-02-09
# Whom:					Shaun Amott <shaun@inerd.com>
#
# $FreeBSD$
#

PORTNAME=	lazarus
PORTVERSION=	0.9.22
CATEGORIES=	editors devel
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION:S/$/-0/}
DIST_SUBDIR=	freepascal

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A portable Delphi-like IDE for the FreePascal compiler

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc \
		fpcmake:${PORTSDIR}/lang/fpc-utils

ONLY_FOR_ARCHS=	i386

USE_ICONV=	yes
USE_GETTEXT=	yes
USE_GNOME=	gtk12 gdkpixbuf
USE_GMAKE=	yes

MAKE_ENV=	OPT="-Sgic -Fu${UNITSDIR}/* -Fl${LOCALBASE}/lib -Fl${X11BASE}/lib"
WRKSRC=		${WRKDIR}/${PORTNAME}

BUILDNAME=	${ARCH}-freebsd
FPC_MINVER=	2.0.4
UNITSDIR=	${LOCALBASE}/lib/fpc/${FPC_MINVER}/units/${BUILDNAME}
BASE_UNITS=	GDBINT GRAPH IBASE LIBASYNC HASH MYSQL NETDB ODBC ORACLE \
		PASJPEG PASZLIB PTHREADS POSTGRES REGEXPR SQLITE
ALL_UNITS=	${BASE_UNITS} BFD FCL FFTW FORMS FPGTK FV GCONF GDBM GGI GNOME GTK GTK2 \
		IMLIB LIBGD LIBPNG NCURSES OPENGL SVGALIB \
		SYSLOG TCL UNZIP UTMP X11 ZLIB ZVT

# Base units
GDBINT_UNIT=	devel/fpc-gdbint
GRAPH_UNIT=	graphics/fpc-graph
IBASE_UNIT=	databases/fpc-ibase
LIBASYNC_UNIT=	net/fpc-libasync
HASH_UNIT=	security/fpc-hash
MYSQL_UNIT=	databases/fpc-mysql
NETDB_UNIT=	net/fpc-netdb
ODBC_UNIT=	databases/fpc-odbc
ORACLE_UNIT=	databases/fpc-oracle
PASJPEG_UNIT=	graphics/fpc-pasjpeg
PASZLIB_UNIT=	archivers/fpc-paszlib
PTHREADS_UNIT=	devel/fpc-pthreads
POSTGRES_UNIT=	databases/fpc-postgres
REGEXPR_UNIT=	devel/fpc-regexpr
SQLITE_UNIT=	databases/fpc-sqlite

# Extra units
BFD_UNIT=	devel/fpc-bfd
FCL_UNIT=	devel/fpc-fcl
FFTW_UNIT=	math/fpc-fftw
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

.include <bsd.port.pre.mk>

.for OPT in ${ALL_UNITS}
BUILD_DEPENDS+=	${UNITSDIR}/${OPT:L}/Package.fpc:${PORTSDIR}/${${OPT}_UNIT}
.endfor

post-depends:
.if exists(${LOCALBASE}/bin/fpc)
FPC_VER!=	${LOCALBASE}/bin/fpc -i -v | ${SED} -n -e 's/^Free Pascal Compiler version //' -e '1p'
FPC_DIR=	${LOCALBASE}/lib/fpc/${FPC_VER}
FPC_REQVER!=	${ECHO_CMD} $$(expr ${FPC_VER:C/^[^\.]*\.//} \>= ${FPC_MINVER:C/^[^\.]*\.//})

.if (${FPC_REQVER} != 1)
IGNORE=	requires fpc ${FPC_MINVER} or above. Please upgrade
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' -e 's|%%DATADIR%%|${DATADIR}|g' \
		${WRKSRC}/${MAKEFILE}
do-build:
	@cd ${WRKSRC} && \
		${GMAKE} ${MAKE_ENV}

post-build:
	@cd ${WRKSRC} && \
		${RM} -Rf Makefile* COPYING* debian

pre-install:
	@${ECHO} "#!/bin/sh" > ${WRKDIR}/lazarus-wrapper
	@${ECHO} "cd ${DATADIR} || exit 1 " >> ${WRKDIR}/lazarus-wrapper
	@${ECHO} "exec ./startlazarus" >> ${WRKDIR}/lazarus-wrapper

do-install:
.for DIRE in components converter debugger designer doceditor docs examples ide ideintf images install \
	languages lcl packager tools units
		${MKDIR} ${DATADIR}/${DIRE}
		@cd ${WRKSRC}/${DIRE} && \
			${FIND} * -type d -exec ${MKDIR} "${DATADIR}/${DIRE}/{}" \; && \
				${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DATADIR}/${DIRE}/{}" \;
.endfor

.for FILE in lazarus startlazarus
	${INSTALL_PROGRAM} ${WRKSRC}/${FILE} ${DATADIR}
.endfor

	${INSTALL_SCRIPT} ${WRKSRC}/localize.sh ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/lazarus-wrapper ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.post.mk>
