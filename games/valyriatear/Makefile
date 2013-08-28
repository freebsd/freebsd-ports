# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	valyriatear
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	games

USE_GITHUB=	yes
GH_ACCOUNT=	Bertram25
GH_PROJECT=	ValyriaTear
GH_COMMIT=	3af3e06

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open Source J-RPG based on the Hero of Allacrost engine

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	boost_thread:${PORTSDIR}/devel/boost-libs \
		vorbis:${PORTSDIR}/audio/libvorbis \
		png15:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg

USES=		cmake gettext
USE_SDL=	sdl image ttf
USE_GL=		gl
USE_OPENAL=	yes
USE_LUA=	5.1
USE_GCC=	any # problems in luabind; recheck with next update

PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/MANUAL ${DOCSDIR}/
.endif

.include <bsd.port.mk>
