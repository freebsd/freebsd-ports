# Created by: Arjan van Leeuwen <avleeuwen@piwebs.com>
# $FreeBSD$

PORTNAME=	cube
DISTVERSION=	2005_08_29
PORTREVISION=	18
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}
DISTFILES=	${CUBE_DATA} ${CUBE_SRC}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL 3D FPS (first person shooter) game

LIB_DEPENDS=	libenet.so:net/enet

USES=		dos2unix gmake
USE_CXXSTD=	gnu++98
EXTRACT_AFTER_ARGS=--exclude enet
ALL_TARGET=	#

CFLAGS+=	-fsigned-char
WRKSRC=		${WRKDIR}/${PORTNAME}_source/src

SUB_FILES=	${ALL_TARGET:S/^/${PORTNAME}_/}

CUBE_DATA=	${PORTNAME}_${DISTVERSION}_unix.tar.gz
CUBE_SRC=	${PORTNAME}_${DISTVERSION}_src.zip

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS DOCS
OPTIONS_MULTI=	FLAVOR
OPTIONS_MULTI_FLAVOR=	CLIENT SERVER
OPTIONS_DEFAULT=	CLIENT SERVER
OPTIONS_SUB=	yes

FLAVOR_DESC=	Clients and servers
CLIENT_DESC=	Build client
CLIENT_USES=			gl xorg
CLIENT_USE=			GL=gl,glu SDL=image,mixer,sdl XORG=x11
CLIENT_LDFLAGS=			-lX11
CLIENT_ALL_TARGET=		client
OPTIMIZED_CFLAGS_CFLAGS=	-O3 -fomit-frame-pointer
SERVER_DESC=	Build dedicated server
SERVER_ALL_TARGET=		server

.include <bsd.port.options.mk>

do-install:
.for f in ${ALL_TARGET}
	${INSTALL_SCRIPT} ${WRKDIR}/cube_${f} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/cube_${f} ${STAGEDIR}${PREFIX}/libexec
.endfor
	(cd ${WRKDIR}/cube && ${COPYTREE_SHARE} \
		"data packages" ${STAGEDIR}${DATADIR})
	(cd ${WRKDIR}/cube/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${WRKDIR}/cube/autoexec.cfg ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/cube/readme.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
