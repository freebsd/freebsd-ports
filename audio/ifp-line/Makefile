# ex:ts=8
# New ports collection makefile for:	ifp-line
# Date created:			Sep 21, 2004
# Whom:				riggs
#
# $FreeBSD$
#

PORTNAME=	ifp-line
PORTVERSION=	0.2.4.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ifp-driver

MAINTAINER=	riggs@rrr.de
COMMENT=	Command line interface to iRiver music players

LIB_DEPENDS=	usb-0.1.8:${PORTSDIR}/devel/libusb

MAN1=		ifp.1

PLIST_FILES+=	bin/ifp

post-install:
	@${CAT} ${.CURDIR}/pkg-message

.include <bsd.port.mk>
