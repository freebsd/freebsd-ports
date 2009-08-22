# New ports collection makefile for:   sage
# Date created:        4 February 2005
# Whom:                Janni
#
# $FreeBSD$
#

PORTNAME=	sage
PORTVERSION=	0.2.0
PORTREVISION=	2
CATEGORIES=	graphics devel
MASTER_SITES=	SF/worldforge/${PORTNAME}%20%28OpenGL%20helper%20lib%29/${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	OpenGL extension library

CONFIGURE_ARGS=	--program-transform-name=
GNU_CONFIGURE=	yes
USE_GL=		yes
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes
USE_SDL=	sdl

MAN3=		sage.3 sage_init.3

CONFIGURE_ENV=	"CFLAGS=${CFLAGS} -I${LOCALBASE}/include"

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
