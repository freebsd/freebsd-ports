# $FreeBSD$

PORTNAME=	fs2open
DISTVERSIONPREFIX=	release_
DISTVERSION=	3_8_0
CATEGORIES=	games

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Open source video engine of FreeSpace 2

LICENSE=	VOLITION
LICENSE_NAME=	Volition Copyright
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror auto-accept

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libpng16.so:graphics/png

USES=		cmake compiler:c++11-lang lua:51 jpeg openal pkgconfig sdl
USE_GITHUB=	yes
GH_ACCOUNT=	scp-fs2open
GH_PROJECT=	fs2open.github.com
GH_TUPLE=	asarium:cmake-modules:7cef957:cmakemodules/cmake/external/rpavlik-cmake-modules \
		sakra:cotire:40a46bf:cotire/cmake/external/cotire
USE_SDL=	sdl2

CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_Doxygen

PLIST_FILES=	bin/fs2_open

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/fs2_open \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
