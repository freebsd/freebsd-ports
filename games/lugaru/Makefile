# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lugaru
PORTVERSION=	1.2
PORTEPOCH=	1
CATEGORIES=	games

MAINTAINER=	salvadore@FreeBSD.org
COMMENT=	3D arcade with unique fighting system and anthropomorphic characters

LICENSE=	GPLv2+ CC-BY-SA-3.0 CC-BY-SA-4.0
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libpng.so:graphics/png \
		libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg

USES=		cmake compiler:c++11-lang gl jpeg openal:soft pkgconfig sdl \
		tar:bzip2 xorg
USE_GL=		gl glu
USE_SDL=	sdl2
USE_XORG=	sm

USE_GITLAB=	yes
GL_ACCOUNT=	osslugaru
GL_COMMIT=	c7b99378439735c60f84869b05c6ebde53083667

CMAKE_ON=	SYSTEM_INSTALL

LDFLAGS_i386=	-Wl,-znotext

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
