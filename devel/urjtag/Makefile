# New ports collection makefile for:	urjtag
# Date created:		2008-01-05
# Whom:			Bruce M. Simpson
#
# $FreeBSD$
#

PORTNAME=	urjtag
PORTVERSION=	0.9
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	bahamasfranks@gmail.com
COMMENT=	Extended utility to work with JTAG-aware boards

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LEX=${LOCALBASE}/bin/flex

CFLAGS+=	--std=c99

MAN1=		jtag.1 bsdl2jtag.1

OPTIONS=	\
	USB	"Build support for USB JTAG adapters"		 On	\
	FTDI	"Build support for FTDI-based USB JTAG adapters" On	\
	JEDEC	"Enable experimental JEDEC flash detection"	 Off

.include <bsd.port.pre.mk>

.if defined(WITH_JEDEC)
CONFIGURE_ARGS+=	--enable-jedec
.endif

.if !defined(WITHOUT_USB)
CONFIGURE_ARGS+=	--with-libusb
.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb:${PORTSDIR}/devel/libusb
.else
EXTRA_PATCHES=	${FILESDIR}/extra-patch-usb
. endif
.endif

.if !defined(WITHOUT_FTDI)
CONFIGURE_ARGS+=	--with-libftdi
LIB_DEPENDS+=	ftdi.15:${PORTSDIR}/devel/libftdi
.endif

.if exists(${LOCALBASE}/lib/libreadline.so.6)
LIB_DEPENDS+=	readline.6:${PORTSDIR}/devel/readline
.endif

.include <bsd.port.post.mk>
