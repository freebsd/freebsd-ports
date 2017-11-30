# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	craft
PORTVERSION=	1.0
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	fbsd
PORTREVISION=	5
CATEGORIES=	games

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Simple Minecraft clone written in C using modern OpenGL

LIB_DEPENDS=	libcurl.so:ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	daniloegea
GH_PROJECT=	Craft

OPTIONS_DEFINE=		SERVER
SERVER_DESC=		Install the craft server
OPTIONS_DEFAULT=	SERVER
OPTIONS_SUB=		yes

USES=		cmake compiler:c11
USE_XORG=	x11 xi xrandr
USE_GL=		gl glu

SERVER_USES=		python:2.7
SERVER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.2:www/py-requests \
			${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3
SERVER_CMAKE_ON=	-DSERVER:BOOL=ON

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MSERVER}
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/world.py ${STAGEDIR}${PYTHON_SITELIBDIR}/craft_world.py
	${INSTALL_SCRIPT} ${WRKSRC}/server.py ${STAGEDIR}${PREFIX}/bin/craft-server
	${INSTALL_LIB} ${WRKSRC}/libworld.so ${STAGEDIR}${PREFIX}/lib/libcraft-world.so
.endif

.include <bsd.port.mk>
