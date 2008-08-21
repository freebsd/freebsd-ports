# New ports collection makefile for:	mpio-driver
# Date created:				19 Jun 2003
# Whom:					Sergey Akifyev <asa@gascom.ru>
#
# $FreeBSD$
#

PORTNAME=	mpiosh
PORTVERSION=	0.7.1.p2
CATEGORIES=	audio
MASTER_SITES=	SF/mpio
DISTNAME=	mpio-${PORTVERSION:S|.p|_pre|}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Digit@lway MPIO MP3 player tool

LIB_DEPENDS=	usb-0.1:${PORTSDIR}/devel/libusb

USE_AUTOTOOLS=	libtool:15
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
