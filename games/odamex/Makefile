# Created by: alepulver
# $FreeBSD$

PORTNAME=	odamex
PORTVERSION=	0.6.2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Odamex/${PORTVERSION}
DISTNAME=	odamex-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Standard in Online Multiplayer Doom

USE_BZIP2=	yes
USE_SDL=	sdl mixer
USES=		cmake
USE_DOS2UNIX=	CMakeLists.txt odalaunch/CMakeLists.txt common/d_main.cpp

OPTIONS_DEFINE=	LAUNCHER

LAUNCHER_DESC=	Enable GUI launcher program

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLAUNCHER}
USE_WX=		2.6+
CMAKE_ARGS+=	-DODALAUNCH_TARGET=on -DNO_AG-ODALAUNCH_TARGET=off
PLIST_SUB+=	LAUNCHER=""
.else
PLIST_SUB+=	LAUNCHER="@comment "
CMAKE_ARGS+=	-DODALAUNCH_TARGET=off
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%DMDIR%%|${DMDIR}|; \
		s|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/common/d_main.cpp
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/odalaunch/src/dlg_main.cpp
	@${REINPLACE_CMD} -e 's|%%WX_VER%%|${WX_VERSION}|' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/odalaunch/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|-waddir /usr/share/doom||' \
		${WRKSRC}/installer/arch/odamex.desktop

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/client/odamex ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/server/odasrv ${PREFIX}/bin
.if ${PORT_OPTIONS:MLAUNCHER}
	${INSTALL_PROGRAM} ${WRKSRC}/odalaunch/odalaunch ${PREFIX}/bin
.endif
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/odamex.wad ${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
.endif
.for f in odamex odasrv
	${INSTALL_DATA} ${WRKSRC}/media/icon_${f}_*.png ${PREFIX}/share/pixmaps
.endfor
.if ${PORT_OPTIONS:MLAUNCHER}
	${INSTALL_DATA} ${WRKSRC}/media/icon_odalaunch_*.png ${PREFIX}/share/pixmaps
.endif
.for f in odamex odasrv
	${INSTALL_DATA} ${WRKSRC}/installer/arch/${f}.desktop ${PREFIX}/share/applications
.endfor
.if ${PORT_OPTIONS:MLAUNCHER}
	${INSTALL_DATA} ${WRKSRC}/installer/arch/odalaunch.desktop ${PREFIX}/share/applications
.endif

.include "${.CURDIR}/../doom-data/Makefile.include"

.include <bsd.port.mk>
