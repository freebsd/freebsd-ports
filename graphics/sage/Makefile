# Created by: Janni
# $FreeBSD$

PORTNAME=	sage
PORTVERSION=	0.2.0
PORTREVISION=	7
CATEGORIES=	graphics devel
MASTER_SITES=	SF/worldforge/${PORTNAME}%20%28OpenGL%20helper%20lib%29/${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	OpenGL extension library

CONFIGURE_ARGS=	--program-transform-name=
GNU_CONFIGURE=	yes
USES=		gl libtool pathfix sdl
USE_GL=		yes
USE_LDCONFIG=	yes
USE_SDL=	sdl

CFLAGS+=	-I${LOCALBASE}/include

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
