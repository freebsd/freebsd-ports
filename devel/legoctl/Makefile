# New ports collection makefile for:	legoctl
# Date created:		2007-05-03
# Whom:			Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	legoctl
PORTVERSION=	0.2
CATEGORIES=	devel
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/ \
		http://bacon.is-a-geek.org/~bacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Lego Mindstorms communication tool

LIB_DEPENDS=	usb-0.1.8:${PORTSDIR}/devel/libusb

MAN1=		legoctl.1

PLIST_FILES=	bin/legoctl lib/liblegoctl.a

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Commands/Legoctl/legoctl ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Libs/C/liblegoctl.a ${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/Commands/Legoctl/legoctl.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
