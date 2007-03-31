# New ports collection makefile for:	libmtp
# Date created:							3 December 2006
# Whom:								Petar Zhivkov Petrov (pesho.petrov@gmail.com)
#
# $FreeBSD$
#

PORTNAME=	libmtp
PORTVERSION=	0.1.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pesho.petrov@gmail.com
COMMENT=	Media Transfer Protocol (MTP) library

LIB_DEPENDS=	usb:${PORTSDIR}/devel/libusb \
		iconv:${PORTSDIR}/converters/libiconv

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib -liconv

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on 4.x
.endif

.include <bsd.port.post.mk>
