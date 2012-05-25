# New ports collection makefile for:	libmtp
# Date created:							3 December 2006
# Whom:								Petar Zhivkov Petrov (pesho.petrov@gmail.com)
#
# $FreeBSD$
#

PORTNAME=	libmtp
PORTVERSION=	1.1.3
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Media Transfer Protocol (MTP) library

LICENSE=	LGPL21

OPTIONS=	MTPZ "Enable functionality to connect to MTPZ devices" on

USE_GNOME=	gnomehack
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if defined(WITHOUT_MTPZ)
CONFIGURE_ARGS+=--disable-mtpz
.else
LIB_DEPENDS+=	gcrypt.18:${PORTSDIR}/security/libgcrypt
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
		'/LIBUSB_REQUIRES/s|libusb-1.0||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|<libusb-1.0/|<|' ${WRKSRC}/src/libusb-glue.h

.include <bsd.port.post.mk>
