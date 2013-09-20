# Created by: gmarco@giovannelli.it
# $FreeBSD$

PORTNAME=	pmars
PORTVERSION=	0.9.2
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/corewar/pMARS/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A portable corewar system with ICWS'94 extensions

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

MAKE_ARGS+=	CFLAGS+="${CFLAGS}" \
		CFLAGS+="-fno-builtin"

MAN6=		pmars.6

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCURSES}
TARGETS+=	curses
CURSES_ARGS+=	CFLAGS+="-DGRAPHX" \
		LIB+="-lcurses"
PLIST_SUB+=	CURSES=""
.else
PLIST_SUB+=	CURSES="@comment "
.endif

.if ${PORT_OPTIONS:MICWS94}
MAKE_ARGS+=	CFLAGS+="-DEXT94"
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
MAKE_ARGS+=	CFLAGS+="-O3 -fomit-frame-pointer"
.endif

.if ${PORT_OPTIONS:MPERMUTATE}
MAKE_ARGS+=	CFLAGS+="-DPERMUTATE"
.endif

.if ${PORT_OPTIONS:MSERVER}
TARGETS+=	server
SERVER_ARGS+=	CFLAGS+="-DSERVER"
PLIST_SUB+=	SERVER=""
.else
PLIST_SUB+=	SERVER="@comment "
.endif

.if ${PORT_OPTIONS:MSMALLMEM}
MAKE_ARGS+=	CFLAGS+="-DSMALLMEM"
.endif

.if ${PORT_OPTIONS:MX11}
USE_XORG=	x11
TARGETS+=	x11
X11_ARGS+=	CFLAGS+="-DXWINGRAPHX" \
		CFLAGS+="-I${LOCALBASE}/include" \
		LIB+="-L${LOCALBASE}/lib -lX11"
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
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-${f} ${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/../doc/pmars.6 ${PREFIX}/man/man6
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.   for f in README config doc warriors
	${CP} -R ${WRKSRC}/../${f} ${DOCSDIR}
.   endfor
.endif

.include <bsd.port.mk>
