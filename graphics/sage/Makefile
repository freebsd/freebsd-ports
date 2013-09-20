# Created by: Janni
# $FreeBSD$

PORTNAME=	sage
PORTVERSION=	0.2.0
PORTREVISION=	3
CATEGORIES=	graphics devel
MASTER_SITES=	SF/worldforge/${PORTNAME}%20%28OpenGL%20helper%20lib%29/${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	OpenGL extension library

CONFIGURE_ARGS=	--program-transform-name=
GNU_CONFIGURE=	yes
USE_GL=		yes
USES=	pathfix
USE_LDCONFIG=	yes
USE_SDL=	sdl

MAN3=		sage.3 sage_init.3

CFLAGS+=	-I${LOCALBASE}/include

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
