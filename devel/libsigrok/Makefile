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
USE_LDCONFIG=	yes

post-patch:
# libusb can be disabled via src.conf(5), so detect via pkg-config
	@${REINPLACE_CMD} -e 's/\(libusb-1\.0\) >= 1\.0\.[0-9]*/\1/' \
		-e '/\*freebsd\*/,/;;/d' \
		${WRKSRC}/configure

.include <bsd.port.mk>
