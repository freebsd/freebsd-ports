PORTNAME=	endless-sky
PORTVERSION=	0.9.16.1
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Space exploration and combat game similar to Escape Velocity
WWW=		https://endless-sky.github.io/

LICENSE=	GPLv3+ CC-BY-4.0 CC-BY-SA-3.0 CC-BY-SA-4.0 PD
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/license.txt

LIB_DEPENDS=	libpng.so:graphics/png \
		libmad.so:audio/libmad \
		libuuid.so:misc/e2fsprogs-libuuid

USE_GITHUB=	yes

USES=		compiler:c++11-lang gl gnome jpeg localbase:ldflags openal scons sdl xorg
USE_SDL=	sdl2
USE_GL=		gl glew

LDFLAGS_i386=	-Wl,-znotext

PORTDATA=	*

post-build:
	@${REINPLACE_CMD} -e 's|/usr/local/|${PREFIX}/|; s|share/games|share|' \
		${WRKSRC}/source/Files.cpp

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
