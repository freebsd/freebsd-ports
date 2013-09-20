# Created by: Bruce M. Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	urjtag
PORTVERSION=	0.10
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extended utility to work with JTAG-aware boards

LICENSE=	GPLv2

BUILD_DEPENDS=	flex:${PORTSDIR}/textproc/flex

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LEX=${LOCALBASE}/bin/flex

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	--std=c99

MAN1=		jtag.1 bsdl2jtag.1

OPTIONS_DEFINE=	USB FTDI JEDEC NLS
OPTIONS_DEFAULT=	USB FTDI
USB_DESC=	Build support for USB JTAG adapters
FTDI_DESC=	Build support for FTDI-based USB JTAG adapters
JEDEC_DESC=	Enable experimental JEDEC flash detection

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJEDEC}
CONFIGURE_ARGS+=	--enable-jedec
.endif

.if ${PORT_OPTIONS:MUSB}
CONFIGURE_ARGS+=	--with-libusb
EXTRA_PATCHES=	${FILESDIR}/extra-patch-usb
.endif

.if ${PORT_OPTIONS:MFTDI}
CONFIGURE_ARGS+=	--with-libftdi
LIB_DEPENDS+=	ftdi:${PORTSDIR}/devel/libftdi
.endif

.if exists(${LOCALBASE}/lib/libreadline.so.6)
LIB_DEPENDS+=	readline.6:${PORTSDIR}/devel/readline
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=	gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=--disable-nls
.endif

post-patch:
# Suppress svn(1) binary detection
	@${REINPLACE_CMD} -e 's|^SVN=.*|SVN=''|' ${WRKSRC}/configure

.include <bsd.port.mk>
