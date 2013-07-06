# $FreeBSD$

PORTNAME=	sdl2_image
PORTVERSION=	2.0.p2
CATEGORIES=	graphics
MASTER_SITES=	http://www.libsdl.org/tmp/SDL_image/release/
DISTNAME=	SDL2_image-2.0.0

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A simple library to load images of various formats as SDL surfaces

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff \
		webp:${PORTSDIR}/graphics/webp

USES=		pkgconfig:build pathfix
USE_AUTOTOOLS=	libtool
USE_SDL=	sdl2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lm
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
