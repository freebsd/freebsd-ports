# Created by: Arjan van Leeuwen <avleeuwen@piwebs.com>
# $FreeBSD$

PORTNAME=	cube
DISTVERSION=	2005_08_29
PORTREVISION=	13
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}
DISTFILES=	${CUBE_DATA} ${CUBE_SRC}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL 3D FPS (first person shooter) game

BUILD_DEPENDS=	${LOCALBASE}/lib/libenet.a:${PORTSDIR}/net/enet

USES=		dos2unix gmake
ALL_TARGET=	#
USE_XORG=	x11

CFLAGS+=	-fsigned-char
WRKSRC=		${WRKDIR}/${PORTNAME}_source/src

SUB_FILES=	cube_client cube_server

CUBE_DATA=	${PORTNAME}_${DISTVERSION}_unix.tar.gz
CUBE_SRC=	${PORTNAME}_${DISTVERSION}_src.zip

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS DOCS
OPTIONS_MULTI=	FLAVOR
OPTIONS_MULTI_FLAVOR=	CLIENT SERVER
OPTIONS_DEFAULT=	CLIENT SERVER

FLAVOR_DESC=	Clients and servers
CLIENT_DESC=	Build client
SERVER_DESC=	Build dedicated server

OPTIONS_SUB=	yes

OPTIMIZED_CFLAGS_CFLAGS=	-O3 -fomit-frame-pointer

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIENT}
USE_GL=		glu
USE_SDL=	image mixer sdl
ALL_TARGET+=	client
CUBE_BIN+=	client
LDFLAGS+=	-lX11
.endif

.if ${PORT_OPTIONS:MSERVER}
ALL_TARGET+=	server
CUBE_BIN+=	server
.endif

do-install:
.for f in ${CUBE_BIN}
	${INSTALL_SCRIPT} ${WRKDIR}/cube_${f} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/cube_${f} ${STAGEDIR}${PREFIX}/libexec
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKDIR}/cube && ${COPYTREE_SHARE} "data packages" ${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${WRKDIR}/cube/autoexec.cfg ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/cube/readme.html ${STAGEDIR}${DOCSDIR}
	(cd ${WRKDIR}/cube/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
