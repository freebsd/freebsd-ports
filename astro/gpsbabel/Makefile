# New ports collection makefile for:	gpsbabel
# Date created:		Apr 2006
# Whom:			Laurent Courty
#
# $FreeBSD$

PORTNAME=	gpsbabel
PORTVERSION=	1.3.5
CATEGORIES=	astro geography
MASTER_SITES=	GENTOO
MASTER_SITE_SUBDIR=	distfiles
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	A gps file translating tool

LIB_DEPENDS=	usb:${PORTSDIR}/devel/libusb \
		expat:${PORTSDIR}/textproc/expat2

USE_AUTOTOOLS=	autoconf:261
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/gpsbabel

.include <bsd.port.mk>
