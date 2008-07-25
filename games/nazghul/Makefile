# New ports collection makefile for:	nazghul
# Date created:		2006-08-02
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nazghul
PORTVERSION=	0.5.6
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A computer role-playing game engine

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_SDL=	sdl image
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
LDFLAGS+=	-lpng
MAKE_ENV=	LDFLAGS="${LDFLAGS}"

post-patch:
	${REINPLACE_CMD} -i "" 's|malloc.h|stdlib.h|g' ${WRKSRC}/src/scheme.c

post-configure:
	${REINPLACE_CMD} -i "" -e 's|^LDFLAGS =*|LDFLAGS =-lpng|g' ${WRKSRC}/src/Makefile

.include <bsd.port.mk>
