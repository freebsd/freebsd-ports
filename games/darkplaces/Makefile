# New ports collection makefile for:	darkplaces
# Date created:				25 Aug 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	darkplaces
PORTVERSION=	20110628
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://offload1.icculus.org:9090/twilight/darkplaces/files/
DISTNAME=	${PORTNAME}engine${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Quake engine modification

USE_ZIP=	yes
USE_GMAKE=	yes
USE_XORG=	xxf86dga xpm
USE_DOS2UNIX=	darkplaces.txt
MAKE_ENV=	DP_FS_BASEDIR="${Q1DIR}"
WRKSRC=		${WRKDIR}/${PORTNAME}

MAKEFILE=	makefile
ALL_TARGET=	#

OPTIONS_MULTI=	MODULE
OPTIONS_MULTI_MODULE=	CLIENT DEDICATED SDL
OPTIONS_DEFAULT=	${OPTIONS_MULTI_MODULE}

CLIENT_DESC=	Build GLX client
DEDICATED_DESC=	Build dedicated server
SDL_DESC=	Build SDL client

PLIST_FILES=	%%DATADIR%%/dummy
PLIST_DIRS=	%%DATADIR%%
PORTDOCS=	darkplaces.txt

.include "${.CURDIR}/../quake-data/Makefile.include"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIENT} || ${PORT_OPTIONS:MSDL}
USE_GL=		glu
# Loads libraries at run-time, thus RUN_DEPENDS.
RUN_DEPENDS+=	${LOCALBASE}/lib/libjpeg.so:${PORTSDIR}/graphics/jpeg \
		${LOCALBASE}/lib/libvorbis.so:${PORTSDIR}/audio/libvorbis
.endif

.if ${PORT_OPTIONS:MCLIENT}
ALL_TARGET+=	cl-release
EXE_TARGETS+=	${PORTNAME}-glx
PLIST_SUB+=	CLIENT=""
PLIST_FILES+=	bin/${PORTNAME}-glx
DESKTOP_ENTRIES+="Darkplaces GLX Client" "" "" "darkplaces-glx" \
		"Game;ActionGame;" "false"
.endif

.if ${PORT_OPTIONS:MDEDICATED}
ALL_TARGET+=	sv-release
EXE_TARGETS+=	${PORTNAME}-dedicated
PLIST_FILES+=	bin/${PORTNAME}-dedicated
.endif

.if ${PORT_OPTIONS:MSDL}
USE_SDL=	sdl
ALL_TARGET+=	sdl-release
EXE_TARGETS+=	${PORTNAME}-sdl
PLIST_FILES+=	bin/${PORTNAME}-sdl
DESKTOP_ENTRIES+="Darkplaces SDL Client" "" "" "darkplaces-sdl" \
		"Game;ActionGame;" "false"
.endif

post-extract:
	@${UNZIP_CMD} ${EXTRACT_BEFORE_ARGS} \
		${WRKDIR}/${PORTNAME}enginesource${PORTVERSION}.zip \
		-d ${WRKDIR}

do-install:
.for f in ${EXE_TARGETS}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
	@${MKDIR} ${DATADIR}
	@${TOUCH} ${DATADIR}/dummy
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/darkplaces.txt ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64: unrecognized command line option "-msse2"
.endif

.include <bsd.port.post.mk>
