# New ports collection makefile for:	libmtp
# Date created:							3 December 2006
# Whom:								Petar Zhivkov Petrov (pesho.petrov@gmail.com)
#
# $FreeBSD$
#

PORTNAME=	libmtp
PORTVERSION=	1.0.2
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	pesho.petrov@gmail.com
COMMENT=	Media Transfer Protocol (MTP) library

LIB_DEPENDS=	iconv:${PORTSDIR}/converters/libiconv

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib -liconv

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb:${PORTSDIR}/devel/libusb
LIBUSB=		libusb
.else
LIBUSB=
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|doc||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/libusb/s//${LIBUSB}/' ${WRKSRC}/libmtp.pc.in

.include <bsd.port.post.mk>
