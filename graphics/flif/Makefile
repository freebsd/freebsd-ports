PORTNAME=	flif
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3-96
PORTREVISION=	1
DISTVERSIONSUFFIX=	-g74ea92b
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Free Lossless Image Format

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE_Apache2

LIB_DEPENDS=	libpng.so:graphics/png

USES=		cmake compiler:c++11-lang gettext-runtime gnome localbase:ldflags pkgconfig sdl shared-mime-info
USE_GITHUB=	yes
GH_ACCOUNT=	FLIF-hub
GH_PROJECT=	FLIF
USE_GNOME=	gdkpixbuf2 glib20
USE_SDL=	sdl2
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_STATIC_LIBS

WRKSRC_SUBDIR=	src

.include <bsd.port.mk>
