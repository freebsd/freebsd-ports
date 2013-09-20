# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdl_image
PORTVERSION=	1.2.12
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.libsdl.org/projects/SDL_image/release/
DISTNAME=	SDL_image-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A simple library to load images of various formats as SDL surfaces

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff \
		webp:${PORTSDIR}/graphics/webp

USES=		pkgconfig:build pathfix
USE_AUTOTOOLS=	libtool
USE_SDL=	sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lm
USE_LDCONFIG=	yes

NO_STAGE=	yes
post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/.libs/showimage ${PREFIX}/bin

.include <bsd.port.mk>
