# New ports collection makefile for:	libmtp
# Date created:							3 December 2006
# Whom:								Petar Zhivkov Petrov (pesho.petrov@gmail.com)
#
# $FreeBSD$
#

PORTNAME=	libmtp
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

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
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|doc||' ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
