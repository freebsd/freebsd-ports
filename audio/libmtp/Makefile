# New ports collection makefile for:	libmtp
# Date created:							3 December 2006
# Whom:								Petar Zhivkov Petrov (pesho.petrov@gmail.com)
#
# $FreeBSD$
#

PORTNAME=	libmtp
PORTVERSION=	1.1.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Media Transfer Protocol (MTP) library

LICENSE=	LGPL21

BUILD_DEPENDS=	pkg-config>0:${PORTSDIR}/devel/pkg-config

OPTIONS_DEFINE=	MTPZ
OPTIONS_DEFAULT=	MTPZ
MTPZ_DESC=	Enable functionality to connect to MTPZ devices

USE_GNOME=	gnomehack
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMTPZ}
LIB_DEPENDS+=	gcrypt:${PORTSDIR}/security/libgcrypt
.else
CONFIGURE_ARGS+=--disable-mtpz
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb:${PORTSDIR}/devel/libusb
CONFIGURE_ENV+=	ac_cv_lib_openusb_openusb_init=no
.else
CONFIGURE_ENV+=	LIBUSB_CFLAGS="-I/usr/include" LIBUSB_LIBS="-lusb" LIBS="-lusb"
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|doc||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		'/if test/s|==|=| ; \
		 /LIBUSB_REQUIRES/s|libusb-1.0||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|<libusb-1.0/|<|' ${WRKSRC}/src/libusb-glue.h

.include <bsd.port.post.mk>
