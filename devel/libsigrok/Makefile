# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	libsigrok
PORTVERSION=	0.5.0
CATEGORIES=	devel
MASTER_SITES=	http://sigrok.org/download/source/libsigrok/

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Framework for hardware logic analyzers, core library

LICENSE=	GPLv3

BUILD_DEPENDS=	doxygen:devel/doxygen
LIB_DEPENDS=	libftdi1.so:devel/libftdi1 \
		libserialport.so:devel/libserialport \
		libvisa.so:devel/librevisa \
		libzip.so:archivers/libzip

GNU_CONFIGURE=	yes
USES=		pathfix libtool pkgconfig
USE_GNOME=	glib20
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	glibmm
INSTALLS_ICONS=	yes

post-patch:
# libusb can be disabled via src.conf(5), so detect via pkg-config
	@${REINPLACE_CMD} -e 's/\(libusb-1\.0\) >= 1\.0\.[0-9]*/\1/' \
		-e '/\*freebsd\*/,/;;/d' \
		${WRKSRC}/configure

.include <bsd.port.mk>
