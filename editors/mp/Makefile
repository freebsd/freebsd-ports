# New ports collection makefile for:	mp
# Date created:			Apr 12, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	mp
PORTVERSION=	3.1.8
CATEGORIES=	editors
MASTER_SITES=	http://triptico.dhis.org/download/

MAINTAINER=	markp@FreeBSD.org

USE_GMAKE=	yes
USE_REINPLACE=	yes
MAKE_ARGS+=	PREFIX="${PREFIX}"
MAKEFILE=	makefile

pre-configure:
	${REINPLACE_CMD} -e "s@gcc -g -Wall@${CC} ${CFLAGS} -Wall@g" ${WRKSRC}/makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp ${PREFIX}/bin

.include <bsd.port.mk>
