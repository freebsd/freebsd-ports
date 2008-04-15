# New ports collection makefile for:	gpsbabel
# Date created:		Apr 2006
# Whom:			Laurent Courty
#
# $FreeBSD$

PORTNAME=	gpsbabel
PORTVERSION=	1.3.4
CATEGORIES=	astro geography
MASTER_SITES=	SFE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A gps file translating tool

LIB_DEPENDS=	usb:${PORTSDIR}/devel/libusb \
		expat:${PORTSDIR}/textproc/expat2

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/gpsbabel

.include <bsd.port.mk>
