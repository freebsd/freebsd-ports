# New ports collection makefile for:	tdl
# Date created:				30 August 2001
# Whom:					petef
#
# $FreeBSD$
#

PORTNAME=	tdl
PORTVERSION=	1.2
CATEGORIES=	devel
MASTER_SITES=	http://www.rrbcurnow.freeuk.com/tdl/

MAINTAINER=	petef@FreeBSD.org

USE_REINPLACE=	yes

MAN1=	tdl.1

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},; s,gcc,${CC},; \
		s,-O2,${CFLAGS},' ${WRKSRC}/Makefile

.include <bsd.port.mk>
