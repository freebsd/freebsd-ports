# New ports collection makefile for:	gpsbabel
# Date created:		Apr 2006
# Whom:			Laurent Courty
#
# $FreeBSD$

PORTNAME=	gpsbabel
PORTVERSION=	1.2.7
CATEGORIES=	astro
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=${PORTNAME}

MAINTAINER=	lrntct@gmail.com
COMMENT=	A gps file translating tool

LIB_DEPENDS=	usb:${PORTSDIR}/devel/libusb \
		expat:${PORTSDIR}/textproc/expat2

PLIST_FILES=	bin/gpsbabel

.include <bsd.port.mk>
