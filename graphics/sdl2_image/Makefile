# $FreeBSD$

PORTNAME=	sdl2_image
PORTVERSION=	2.0.0
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.libsdl.org/projects/SDL_image/release/
DISTNAME=	SDL2_image-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A simple library to load images of various formats as SDL surfaces

LICENSE=	ZLIB

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libwebp.so:${PORTSDIR}/graphics/webp

USES=		pkgconfig:build pathfix gmake
USE_AUTOTOOLS=	libtool
USE_SDL=	sdl2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lm
USE_LDCONFIG=	yes

.include <bsd.port.mk>
