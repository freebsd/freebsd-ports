PORTNAME=	flif
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Free Lossless Image Format

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE_Apache2

LIB_DEPENDS=	libinotify.so:devel/libinotify \
		libpng.so:graphics/png

USES=		cmake compiler:c++11-lang cpe gettext-runtime gnome localbase:ldflags pkgconfig sdl shared-mime-info
USE_GNOME=	gdkpixbuf2 glib20
USE_SDL=	sdl2
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	FLIF-hub
GH_PROJECT=	FLIF

CMAKE_OFF=	BUILD_STATIC_LIBS

WRKSRC_SUBDIR=	src

.include <bsd.port.mk>
