# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	darkplaces
PORTVERSION=	20140513
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://icculus.org/twilight/darkplaces/files/
DISTNAME=	${PORTNAME}engine${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quake engine modification

# Loads libraries at run-time, thus RUN_DEPENDS.
RUN_DEPENDS=	${LOCALBASE}/lib/libvorbis.so:audio/libvorbis

USES=		gmake jpeg zip:infozip
USE_XORG=	xxf86dga xpm
MAKE_ENV=	DP_FS_BASEDIR="${Q1DIR}" DP_LINK_JPEG=dlopen
WRKSRC=		${WRKDIR}/${PORTNAME}

MAKEFILE=	makefile
ALL_TARGET=	#

OPTIONS_DEFINE=	DOCS SDL1
OPTIONS_DEFINE_i386=	SSE
OPTIONS_DEFINE_amd64=	SSE
OPTIONS_MULTI=	MODULE
MODULE_DESC=	Components
OPTIONS_MULTI_MODULE=	GLX SDL SERVER
OPTIONS_DEFAULT=	${OPTIONS_MULTI_MODULE}
OPTIONS_DEFAULT_amd64=	SSE
OPTIONS_SUB=	yes

GLX_DESC=	Build GLX client
SDL_DESC=	Build SDL client
SDL1_DESC=	Use SDL v1.2 instead of v2.0
SERVER_DESC=	Build dedicated server

.include "${.CURDIR}/../quake-data/Makefile.include"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGLX} || ${PORT_OPTIONS:MSDL}
USE_GL=		glu
PLIST_SUB+=	CLIENT=""
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if ${PORT_OPTIONS:MGLX}
ALL_TARGET+=	cl-release
EXE_TARGETS+=	${PORTNAME}-glx
DESKTOP_ENTRIES+="Darkplaces (GLX client)" "Quake engine modification (GLX)" \
		darkplaces darkplaces-glx "Game;Shooter;" false
.endif

.if ${PORT_OPTIONS:MSERVER}
ALL_TARGET+=	sv-release
EXE_TARGETS+=	${PORTNAME}-dedicated
.endif

.if ${PORT_OPTIONS:MSDL}
. if ${PORT_OPTIONS:MSDL1}
USE_SDL=	sdl
ALL_TARGET+=	sdl-release
. else
USE_SDL=	sdl2
ALL_TARGET+=	sdl2-release
. endif
EXE_TARGETS+=	${PORTNAME}-sdl
DESKTOP_ENTRIES+="Darkplaces (SDL client)" "Quake engine modification (SDL)" \
		darkplaces darkplaces-sdl "Game;Shooter;" false
.endif

.if ! ${PORT_OPTIONS:MSSE}
CFLAGS+=	-DNO_SSE=1
.endif

post-extract:
	@${UNZIP_CMD} ${EXTRACT_BEFORE_ARGS} \
		${WRKDIR}/${PORTNAME}enginesource${PORTVERSION}.zip \
		-d ${WRKDIR}

post-patch:
	@${REINPLACE_CMD} 's,/usr/X11R6,${LOCALBASE},g' \
		${WRKSRC}/makefile \
		${WRKSRC}/makefile.inc \
		${WRKSRC}/BSDmakefile
.if ! ${PORT_OPTIONS:MSSE}
	@${REINPLACE_CMD} '/^CFLAGS_SSE/ d' ${WRKSRC}/makefile.inc
.endif

do-install:
	${INSTALL_PROGRAM} ${EXE_TARGETS:S,^,${WRKSRC}/,} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/darkplaces.txt ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MGLX} || ${PORT_OPTIONS:MSDL}
.for i in 16 24 32 48 64 72
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/ && \
	${INSTALL_DATA} ${WRKSRC}/darkplaces${i}x${i}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/darkplaces.png
.endfor
.endif

.include <bsd.port.mk>
