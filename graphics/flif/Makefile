PORTNAME=	flif
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Free Lossless Image Format
WWW=		https://flif.info/ \
		https://github.com/FLIF-hub/FLIF

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC:H}/LICENSE_Apache2

LIB_DEPENDS=	libpng.so:graphics/png
TEST_DEPENDS=	convert:graphics/ImageMagick7

USES=		cmake compiler:c++11-lang cpe gettext-runtime gnome localbase:ldflags pkgconfig sdl shared-mime-info
USE_GNOME=	gdkpixbuf glib20
USE_SDL=	sdl2
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	FLIF-hub
GH_PROJECT=	FLIF

CMAKE_OFF=	BUILD_STATIC_LIBS

TEST_TARGET=	test

WRKSRC_SUBDIR=	src
PATCH_WRKSRC=	${WRKSRC:H}

.include <bsd.port.mk>
