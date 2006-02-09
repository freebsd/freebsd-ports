# New ports collection makefile for:	biloba
# Date created:		02 Oct 2005
# Whom:			Dmitry Marakasov <amdmi3@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	biloba
PORTVERSION=	0.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	amdmi3@mail.ru
COMMENT=	A strategy board game for 2 to 4 players

USE_SDL=	image mixer sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' \
	    ${WRKSRC}/src/Makefile.server
	@${REINPLACE_CMD} -e 's|SDL/|SDL11/|' ${WRKSRC}/configure

.include <bsd.port.mk>
