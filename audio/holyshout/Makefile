# New ports collection makefile for:	holyshout
# Date created:				26 Aug 2000
# Whom:					JunSeon Oh <hollywar@mail.holywar.net>
#
# $FreeBSD$
#

PORTNAME=	holyshout
PORTVERSION=	0.1.1
CATEGORIES=	audio net
MASTER_SITES=	ftp://ftp.holywar.net/pub/FreeBSD/

MAINTAINER=	hollywar@mail.holywar.net

USE_GMAKE=	yes

post-patch:
	(cd ${WRKSRC} && find . -name Makefile | xargs ${PERL} -pi -e \
		"s@-O20@${CFLAGS}@g")
	(cd ${WRKSRC} && find . -name Makefile | xargs ${PERL} -pi -e \
		"s@-O2@${CFLAGS}@g")

.include <bsd.port.mk>
