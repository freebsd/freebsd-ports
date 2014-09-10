# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nazghul
PORTVERSION=	0.7.1
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Computer role-playing game engine

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png

USE_SDL=	sdl image mixer
GNU_CONFIGURE=	yes
USES=		gmake

post-patch:
	${REINPLACE_CMD} -i "" 's|malloc.h|stdlib.h|g' ${WRKSRC}/src/scheme.c

.include <bsd.port.mk>
