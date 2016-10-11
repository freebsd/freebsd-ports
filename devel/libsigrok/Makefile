# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	libsigrok
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://sigrok.org/download/source/libsigrok/

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Framework for hardware logic analyzers, core library

LICENSE=	GPLv3

LIB_DEPENDS=	libserialport.so:devel/libserialport \
		libzip.so:archivers/libzip

GNU_CONFIGURE=	yes
USES=		gmake pathfix libtool pkgconfig
USE_GNOME=	glib20
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	yes
LDFLAGS+=	-L/usr/lib -lusb
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

# Workaround for libusb not knowing LIBUSB_CLASS_APPLICATION
.if (${OSVERSION} >= 1100000 && ${OSVERSION} < 1100029) || (${OSVERSION} < 1000715)
CFLAGS+=	-DLIBUSB_CLASS_APPLICATION=0xfe
.endif

.include <bsd.port.post.mk>
