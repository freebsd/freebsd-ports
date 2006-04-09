# New ports collection makefile for:   games/pmars
# Date created:        15 Feb 1999
# Whom:                gmarco@giovannelli.it
#
# $FreeBSD$
#

PORTNAME=	pmars
PORTVERSION=	0.9.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	corewar

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	A portable corewar system with ICWS'94 extensions

WRKSRC=		${WRKDIR}/${DISTNAME}/src

OPTIONS=	CURSES "Build the console (graphical) interface" on \
		ICWS94 "Enable ICWS'94 support" on \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		PERMUTATE "Enable the -P switch" on \
		SERVER "Build the command-line interface" on \
		SMALLMEM "Use 16-bit addresses (smaller)" off \
		X11 "Build the X11 (graphical) interface" on

MAKE_ARGS+=	CFLAGS+="${CFLAGS}" \
		CFLAGS+="-fno-builtin"

MAN6=		pmars.6

.include <bsd.port.pre.mk>

.if !defined(WITH_CURSES) && !defined(WITH_SERVER) && !defined(WITH_X11)
IGNORE=		Please select at least one interface
.endif

.if defined(WITH_ICWS94)
MAKE_ARGS+=	CFLAGS+="-DEXT94"
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
MAKE_ARGS+=	CFLAGS+="-O3 -fomit-frame-pointer"
.endif

.if defined(WITH_PERMUTATE)
MAKE_ARGS+=	CFLAGS+="-DPERMUTATE"
.endif

.if defined(WITH_SMALLMEM)
MAKE_ARGS+=	CFLAGS+="-DSMALLMEM"
.endif

.if defined(WITH_CURSES)
TARGETS+=	curses
CURSES_ARGS+=	CFLAGS+="-DGRAPHX" \
		LIB+="-lcurses"
PLIST_SUB+=	CURSES=""
.else
PLIST_SUB+=	CURSES="@comment "
.endif

.if defined(WITH_SERVER)
TARGETS+=	server
SERVER_ARGS+=	CFLAGS+="-DSERVER"
PLIST_SUB+=	SERVER=""
.else
PLIST_SUB+=	SERVER="@comment "
.endif

.if defined(WITH_X11)
USE_XLIB=	yes
TARGETS+=	x11
X11_ARGS+=	CFLAGS+="-DXWINGRAPHX" \
		CFLAGS+="-I${X11BASE}/include" \
		LIB+="-L${X11BASE}/lib -lX11"
PLIST_SUB+=	X11=""
.else
PLIST_SUB+=	X11="@comment "
.endif

do-build:
.for f in ${TARGETS}
	@(cd ${BUILD_WRKSRC}; ${MAKE} ${MAKE_ARGS} ${${f:U}_ARGS} \
		${ALL_TARGET} clean)
	@(cd ${BUILD_WRKSRC}; ${MV} ${PORTNAME} ${PORTNAME}-${f})
.endfor

do-install:
.for f in ${TARGETS}
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-${f} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.   for f in README config doc warriors
	@${CP} -R ${WRKSRC}/../${f} ${DOCSDIR}
.   endfor
	@${INSTALL_MAN} ${WRKSRC}/../doc/pmars.6 ${PREFIX}/man/man6
.endif

.include <bsd.port.post.mk>
