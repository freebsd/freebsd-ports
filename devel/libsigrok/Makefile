PORTNAME=	libsigrok
PORTVERSION=	0.5.2
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://sigrok.org/download/source/libsigrok/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Framework for hardware logic analyzers, core library
WWW=		https://sigrok.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	doxygen:devel/doxygen
LIB_DEPENDS=	libcheck.so:devel/check \
		libftdi1.so:devel/libftdi1 \
		libhidapi.so:comms/hidapi \
		libserialport.so:devel/libserialport \
		libvisa.so:devel/librevisa \
		libzip.so:archivers/libzip

USES=		compiler:c11 gnome libtool pathfix pkgconfig python:-3.9,build \
		shared-mime-info
USE_GNOME=	glibmm
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

MAKE_JOBS_UNSAFE=	yes

INSTALL_TARGET=	install-strip

post-patch:
# libusb can be disabled via src.conf(5), so detect via pkg-config
	@${REINPLACE_CMD} -e 's/\(libusb-1\.0\) >= 1\.0\.[0-9]*/\1/' \
		-e '/\*freebsd\*/,/;;/d' \
		${WRKSRC}/configure

.include <bsd.port.mk>
