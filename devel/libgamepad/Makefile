# New ports collection makefile for:	libgamepad
# Date created:		Jul 2008
# Whom:			Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	libgamepad
PORTVERSION=	0.1.1
CATEGORIES=	devel games
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/ \
		http://jbacon.dyndns.org/~bacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Generic gamepad API

pre-build:
	(cd ${WRKSRC} && make depend)

MAN3=		libgamepad.3

.include <bsd.port.mk>
