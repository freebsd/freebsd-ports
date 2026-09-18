PORTNAME=	lugaru
PORTVERSION=	1.2
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D arcade with unique fighting system and anthropomorphic characters
WWW=		https://bitbucket.org/osslugaru/lugaru/wiki/Home

LICENSE=	GPLv2+ CC-BY-SA-3.0 CC-BY-SA-4.0
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING.txt

DEPRECATED=	No release in 9 years, does not build with CMake 4
EXPIRATION_DATE=2026-11-30

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
GL_TAGNAME=	c7b99378439735c60f84869b05c6ebde53083667

CMAKE_ON=	SYSTEM_INSTALL

LDFLAGS_i386=	-Wl,-znotext

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
