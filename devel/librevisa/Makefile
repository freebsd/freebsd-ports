# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	librevisa
PORTVERSION=	0.0.20130412
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.librevisa.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for interfacing test and measurement equipment

USES=		gmake pathfix libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

# Workaround FreeBSD 9.1+ libusb not knowing LIBUSB_CLASS_APPLICATION
CPPFLAGS+=	-DLIBUSB_CLASS_APPLICATION=0xfe

post-install:
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/lib/libvisa.so

.include <bsd.port.mk>
