# New ports collection makefile for:	holyshout
# Date created:				26 Aug 2000
# Whom:					JunSeon Oh <hollywar@mail.holywar.net>
#
# $FreeBSD$
#

PORTNAME=	holyshout
PORTVERSION=	0.1.3
CATEGORIES=	audio net
MASTER_SITES=	ftp://ftp.holywar.net/pub/FreeBSD/

MAINTAINER=	hollywar@mail.holywar.net

USE_GMAKE=	yes
USE_REINPLACE=	yes

post-patch:
	(find ${WRKSRC} -name Makefile | xargs ${REINPLACE_CMD} -e \
		"s@-O20@${CFLAGS}@g ; s@-O2@${CFLAGS}@g")
	${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
