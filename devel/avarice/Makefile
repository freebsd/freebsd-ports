# New ports collection makefile for:	avarice
# Date created:				13 April 2003
# Whom:					Brian Dean <bsd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	avarice
PORTVERSION=	2.10
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	Atmel AVR JTAG programmer and debugging interface for avr-gdb

BUILD_DEPENDS=	${LOCALBASE}/lib/libbfd.a:${PORTSDIR}/devel/libbfd \
		${LOCALBASE}/lib/libiberty.a:${PORTSDIR}/devel/gnulibiberty

USE_BZIP2=	yes
USE_PERL5=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib

MAN1=		avarice.1 ice-gdb.1 ice-insight.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1.8:${PORTSDIR}/devel/libusb
.endif

.include <bsd.port.post.mk>
