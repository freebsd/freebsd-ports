# New ports collection makefile for:	mpio-driver
# Date created:				19 Jun 2003
# Whom:					Sergey Akifyev <asa@gascom.ru>
#
# $FreeBSD$
#

PORTNAME=	mpiosh
PORTVERSION=	0.7.1.p2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mpio
DISTNAME=	mpio-${PORTVERSION:S|.p|_pre|}

MAINTAINER=	asa@gascom.ru
COMMENT=	Digit@lway MPIO MP3 player tool

LIB_DEPENDS=	usb-0.1:${PORTSDIR}/devel/libusb

USE_ICONV=	yes
USE_LIBTOOL_VER=	13
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_TARGET=
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
