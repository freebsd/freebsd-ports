# New ports collection makefile for:	nazghul
# Date created:		2006-08-02
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nazghul
PORTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A computer role-playing game engine

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_SDL=	sdl image
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

post-patch:
	${REINPLACE_CMD} -i "" 's|malloc.h|stdlib.h|g' ${WRKSRC}/src/scheme.c

.include <bsd.port.mk>
