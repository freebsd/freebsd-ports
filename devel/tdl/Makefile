# New ports collection makefile for:	tdl
# Date created:				30 August 2001
# Whom:					petef
#
# $FreeBSD$
#

PORTNAME=	tdl
PORTVERSION=	1.3
CATEGORIES=	devel
MASTER_SITES=	http://www.rrbcurnow.freeuk.com/tdl/

MAINTAINER=	petef@FreeBSD.org
COMMENT=	To-do list manager

USE_REINPLACE=	yes

MAN1=	tdl.1

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},; s,gcc,${CC},; \
		s,^CFLAGS=,CFLAGS+=,' ${WRKSRC}/Makefile

.include <bsd.port.mk>
