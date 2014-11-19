# Created by: gmarco@giovannelli.it
# $FreeBSD$

PORTNAME=	pmars
PORTVERSION=	0.9.2
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/corewar/pMARS/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable corewar system with ICWS'94 extensions

LICENSE=	GPLv2 # or later
LICENSE_FILE=	${WRKSRC}/../COPYING

WRKSRC=		${WRKDIR}/${DISTNAME}/src

OPTIONS_MULTI=	INT
OPTIONS_MULTI_INT=	CURSES SERVER X11
OPTIONS_DEFINE=	ICWS94 OPTIMIZED_CFLAGS PERMUTATE SMALLMEM DOCS
OPTIONS_DEFAULT=	CURSES ICWS94 OPTIMIZED_CFLAGS PERMUTATE SERVER X11
CURSES_DESC=	Build the console (graphical) interface
ICWS94_DESC=	Enable ICWS'94 support
PERMUTATE_DESC=	Enable the -P switch
SERVER_DESC=	Build the command-line interface
SMALLMEM_DESC=	Use 16-bit addresses (smaller)

OPTIONS_SUB=	yes

MAKE_ARGS+=	CFLAGS+="${CFLAGS}" \
		CFLAGS+="-fno-builtin"

ICWS94_MAKE_ARGS=	CFLAGS+="-DEXT94"
OPTIMIZED_CFLAGS_MAKE_ARGS=	CFLAGS+="-O3 -fomit-frame-pointer"
PERMUTATE_MAKE_ARGS=	CFLAGS+="-DPERMUTATE"
SMALLMEM_MAKE_ARGS=	CFLAGS+="-DSMALLMEM"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCURSES}
TARGETS+=	curses
CURSES_ARGS+=	CFLAGS+="-DGRAPHX" \
		LIB+="-lcurses"
.endif

.if ${PORT_OPTIONS:MSERVER}
TARGETS+=	server
SERVER_ARGS+=	CFLAGS+="-DSERVER"
.endif

.if ${PORT_OPTIONS:MX11}
USE_XORG=	x11
TARGETS+=	x11
X11_ARGS+=	CFLAGS+="-DXWINGRAPHX" \
		CFLAGS+="-I${LOCALBASE}/include" \
		LIB+="-L${LOCALBASE}/lib -lX11"
.endif

do-build:
.for f in ${TARGETS}
	@(cd ${BUILD_WRKSRC}; ${MAKE} ${MAKE_ARGS} ${${f:tu}_ARGS} \
		${ALL_TARGET} clean)
	@(cd ${BUILD_WRKSRC}; ${MV} ${PORTNAME} ${PORTNAME}-${f})
.endfor

do-install:
.for f in ${TARGETS}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/../doc/pmars.6 ${STAGEDIR}${PREFIX}/man/man6
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/.. && ${COPYTREE_SHARE} "README config doc warriors" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
