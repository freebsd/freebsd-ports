# New ports collection makefile for:	wy60
# Date created:		2002-06-12
# Whom:			Christian Weisgerber <naddy@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	wy60
PORTVERSION=	2.0.2
CATEGORIES=	comms
MASTER_SITES=	http://gutschke.com/wy60/html/archive/

MAINTAINER=	naddy@FreeBSD.org

GNU_CONFIGURE=	yes

MAN1=		wy60.1

post-install:
	${MKDIR} ${PREFIX}/share/examples/wy60
	${INSTALL_DATA} ${WRKSRC}/wy60.rc ${PREFIX}/share/examples/wy60

.include <bsd.port.mk>
