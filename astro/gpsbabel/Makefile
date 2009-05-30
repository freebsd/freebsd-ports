# New ports collection makefile for:	gpsbabel
# Date created:		Apr 2006
# Whom:			Laurent Courty
#
# $FreeBSD$

PORTNAME=	gpsbabel
PORTVERSION=	1.3.6
CATEGORIES=	astro geography
MASTER_SITES=	http://www.lexort.com/pkgsrc/distfiles/

MAINTAINER=	wenheping@gmail.com
COMMENT=	A gps file translating tool

LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2

USE_AUTOTOOLS=	autoconf:262
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-expathdr=${LOCALBASE}/include \
		--with-libexpat=${LOCALBASE}/lib

PLIST_FILES=	bin/gpsbabel

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb:${PORTSDIR}/devel/libusb
.else
EXTRA_PATCHES=	${FILESDIR}/extra-patch-libusb
.endif

.include <bsd.port.post.mk>
