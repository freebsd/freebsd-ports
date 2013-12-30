# Created by: Bruce M. Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	urjtag
PORTVERSION=	0.10
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extended utility to work with JTAG-aware boards

LICENSE=	GPLv2

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_BZIP2=	yes
USES=		gmake readline shebangfix
SHEBANG_FILES=	src/bsdl2jtag
USE_CSTD=	c99
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	USB FTDI JEDEC NLS
OPTIONS_DEFAULT=	USB FTDI
OPTIONS_SUB=	yes
USB_DESC=	Build support for USB JTAG adapters
FTDI_DESC=	Build support for FTDI-based USB JTAG adapters
JEDEC_DESC=	Enable experimental JEDEC flash detection

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJEDEC}
CONFIGURE_ARGS+=	--enable-jedec
.endif

.if ${PORT_OPTIONS:MUSB}
CONFIGURE_ARGS+=	--with-libusb=/usr
.endif

.if ! ${PORT_OPTIONS:MFTDI}
CONFIGURE_ARGS+=	--without-libftdi
.else
LIB_DEPENDS+=	libftdi.so:${PORTSDIR}/devel/libftdi
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
.else
CONFIGURE_ARGS+=--disable-nls
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000033
BUILD_DEPENDS+=	flex>0:${PORTSDIR}/textproc/flex
CONFIGURE_ENV+=	LEX=${LOCALBASE}/bin/flex
.endif

post-patch:
# Suppress svn(1) binary detection
	@${REINPLACE_CMD} -e \
		's|^SVN=.*|SVN=''| ; \
      		 s|-Lwith_libusb |-L$$with_libusb/lib | ; \
		 s|-I$$with_libusb"|-I$$with_libusb/include"|' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
