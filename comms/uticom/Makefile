# Ports collection makefile for:	uticom
# Date created:				01-12-2005
# Whom:					Dmitry Komissaroff <dxi@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	uticom
PORTVERSION=	0.3
CATEGORIES=	comms kld
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTNAME=	 ${PORTNAME}-${PORTVERSION}

MAINTAINER=	dxi@mail.ru
COMMENT=	A FreeBSD Driver for TUSB3410 uart-to-usb converter

NO_PACKAGE=	Should be in sync with the kernel to work correctly

ONLY_FOR_ARCHS=	i386
SRCPREFIX?=	/usr/src

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
LOCALBASE=	/boot/kernel

PLIST_FILES=	uticom.ko

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800064
BROKEN=		does not compile
.endif

# Make sure kernel sources are present before going any further
.if ! exists(${SRCPREFIX}/sys/dev/usb/usb.c)
IGNORE=	you need to extract kernel source tree before building this package
.endif

.include <bsd.port.post.mk>
