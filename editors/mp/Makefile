# New ports collection makefile for:	mp
# Date created:			Apr 12, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	mp
PORTVERSION=	3.1.5
CATEGORIES=	editors
MASTER_SITES=	http://www.triptico.com/download/

MAINTAINER=	markp@FreeBSD.org

USE_GMAKE=	yes
MAKE_ARGS+=	PREFIX="${PREFIX}"
MAKEFILE=	makefile

pre-configure:
	${PERL} -pi -e "s@gcc -g -Wall@${CC} ${CFLAGS} -Wall@g" ${WRKSRC}/makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp ${PREFIX}/bin

.include <bsd.port.mk>
