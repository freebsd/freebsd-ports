# New ports collection makefile for:	wy60
# Date created:		2002-06-12
# Whom:			Christian Weisgerber <naddy@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	wy60
PORTVERSION=	2.0.8
CATEGORIES=	comms
MASTER_SITES=	http://gutschke.com/wy60/html/archive/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Curses-based emulator for the Wyse 60 terminal

GNU_CONFIGURE=	yes

MAN1=		wy60.1

pre-build:
	@${CP} ${WRKSRC}/wy60.rc ${WRKSRC}/wy60.rc.sample

.include <bsd.port.mk>
