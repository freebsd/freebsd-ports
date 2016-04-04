# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nazghul
PORTVERSION=	0.7.1
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Computer role-playing game engine

LICENSE=	GPLv2+ # GPLv3 text bundled, but sources mention GPLv2+

LIB_DEPENDS=	libpng.so:graphics/png

USE_SDL=	sdl image mixer
GNU_CONFIGURE=	yes
USES=		gmake

post-patch:
	${REINPLACE_CMD} -i "" 's|malloc.h|stdlib.h|g' ${WRKSRC}/src/scheme.c

.include <bsd.port.mk>
