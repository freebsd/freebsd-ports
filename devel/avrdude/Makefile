# New ports collection makefile for:	avrdude
# Date created:				8 April 2003
# Whom:					Brian Dean <bsd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	avrdude
PORTVERSION=	5.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	avrdude

MAINTAINER=	bsd@FreeBSD.org
COMMENT=	Program for programming the on-chip memory of Atmel AVR CPUs

LIB_DEPENDES=	usb-0.1.8:${PORTSDIR}/devel/libusb

MAN1=		avrdude.1
MANCOMPRESSED=	no

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
CONFIGURE_ENV=	CFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib

.include <bsd.port.mk>
