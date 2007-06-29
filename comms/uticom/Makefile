# Ports collection makefile for:	uticom
# Date created:				01-12-2005
# Whom:					Dmitry Komissaroff <dxi@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	uticom
PORTVERSION=	0.2
CATEGORIES=	comms kld
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	 ${PORTNAME}-${PORTVERSION}

MAINTAINER=	dxi@mail.ru
COMMENT=	A FreeBSD Driver for TUSB3410 uart-to-usb converter

NO_PACKAGE=	"Should be in sync with the kernel to work correctly"

ONLY_FOR_ARCHS=	i386
SRCPREFIX?=	/usr/src

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
LOCALBASE=	/boot/kernel

PLIST_FILES=	uticom.ko

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		FreeBSD < 5.0 are not supported
.endif

# Make sure kernel sources are present before going any further
.if ! exists(${SRCPREFIX}/sys/dev/usb/usb.c)
IGNORE=	you need to extract kernel source tree before building this package
.endif

.include <bsd.port.post.mk>
