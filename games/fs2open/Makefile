PORTNAME=	fs2open
DISTVERSIONPREFIX=	release_
DISTVERSION=	24_2_0
CATEGORIES=	games

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Open source video engine of FreeSpace 2
WWW=		http://scp.indiegames.us

LICENSE=	VOLITION
LICENSE_NAME=	Volition Copyright
LICENSE_FILE=	${WRKSRC}/Copying.md
LICENSE_PERMS=	dist-mirror auto-accept

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libjansson.so:devel/jansson \
		libpng.so:graphics/png \
		libfreetype.so:print/freetype2

USES=		cmake compiler:c++11-lib lua:51 jpeg openal pkgconfig sdl
USE_GITHUB=	yes
GH_ACCOUNT=	scp-fs2open
GH_PROJECT=	fs2open.github.com
GH_TUPLE=	asarium:cmake-modules:7cef957:cmakemodules/cmake/external/rpavlik-cmake-modules \
		asarium:libRocket:ae8a8d9:libRocket/lib/libRocket
USE_SDL=	sdl2

LDFLAGS_i386=	-Wl,-znotext

PLIST_FILES=	bin/fs2_open

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/fs2_open \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
