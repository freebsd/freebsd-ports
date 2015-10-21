# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	endless-sky
PORTVERSION=	0.8.4
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Space exploration and combat game similar to Escape Velocity

LICENSE=	GPLv3 # or later

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png

BROKEN_FreeBSD_9=	does not build

USE_GITHUB=	yes

USES=		compiler:c++11-lib jpeg localbase openal scons
USE_SDL=	sdl2
USE_GL=		gl glew
INSTALLS_ICONS=	yes

PORTDATA=	*

post-build:
	@${REINPLACE_CMD} -e 's|/usr/local/|${PREFIX}/|; s|share/games|share|' \
		${WRKSRC}/source/Files.cpp

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
