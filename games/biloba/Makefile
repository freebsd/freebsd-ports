# New ports collection makefile for:	biloba
# Date created:		02 Oct 2005
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	biloba
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	A strategy board game for 2 to 4 players

USE_SDL=	image mixer sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' \
	    ${WRKSRC}/src/Makefile.server

.include <bsd.port.mk>
