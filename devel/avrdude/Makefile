# New ports collection makefile for:	avrdude
# Date created:				8 April 2003
# Whom:					Brian Dean <bsd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	avrdude
PORTVERSION=	5.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	avrdude

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	Program for programming the on-chip memory of Atmel AVR CPUs

MAN1=		avrdude.1
MANCOMPRESSED=	no

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1.8:${PORTSDIR}/devel/libusb
.endif

.include <bsd.port.post.mk>
