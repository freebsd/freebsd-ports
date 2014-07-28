# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	libsigrok
PORTVERSION=	0.3.0
CATEGORIES=	devel
MASTER_SITES=	http://sigrok.org/download/source/libsigrok/

MAINTAINER=	uffe@uffe.org
COMMENT=	Framework for hardware logic analyzers, core library

LICENSE=	GPLv3

LIB_DEPENDS=	libserialport.so:${PORTSDIR}/devel/libserialport \
		libzip.so:${PORTSDIR}/archivers/libzip

GNU_CONFIGURE=	yes
USES=		gmake pathfix libtool pkgconfig
USE_GNOME=	glib20
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	yes
LDFLAGS+=	-L/usr/lib -lusb
USE_LDCONFIG=	yes

# Workaround for libusb not knowing LIBUSB_CLASS_APPLICATION
CFLAGS+=	-DLIBUSB_CLASS_APPLICATION=0xfe

.include <bsd.port.mk>
