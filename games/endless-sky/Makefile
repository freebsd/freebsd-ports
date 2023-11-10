PORTNAME=	endless-sky
PORTVERSION=	0.10.4
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Space exploration and combat game similar to Escape Velocity
WWW=		https://endless-sky.github.io/

LICENSE=	GPLv3+ GPLv2 CC-BY-2.0 CC-BY-3.0 CC-BY-4.0 CC-BY-SA-3.0 CC-BY-SA-4.0 PD CC0-1.0
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/copyright
LICENSE_FILE_GPLv3+ =	${WRKSRC}/license.txt

LIB_DEPENDS=	libpng.so:graphics/png \
		libmad.so:audio/libmad \
		libuuid.so:misc/e2fsprogs-libuuid

USE_GITHUB=	yes

USES=		cmake compiler:c++11-lang gl jpeg openal sdl
USE_SDL=	sdl2
USE_GL=		gl glew
CMAKE_OFF=	ES_USE_VCPKG
CMAKE_ARGS=	-DCMAKE_INSTALL_DOCDIR="${DOCSDIR}"

LDFLAGS_i386=	-Wl,-znotext

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-build:
	@${REINPLACE_CMD} -e 's|/usr/local/|${PREFIX}/|; s|share/games|share|' \
		${WRKSRC}/source/Files.cpp

.include <bsd.port.mk>
