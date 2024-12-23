PORTNAME=	libcdr
DISTVERSION=	0.1.8
CATEGORIES=	graphics devel
MASTER_SITES=	LODEV
PKGNAMESUFFIX=	01

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library and tools for parsing Corel Draw file format
WWW=		https://wiki.documentfoundation.org/DLP/Libraries/libcdr

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYING.MPL

BUILD_DEPENDS=	${LOCALBASE}/include/boost/optional.hpp:devel/boost-libs
LIB_DEPENDS=	libicui18n.so:devel/icu \
		librevenge-0.0.so:textproc/librevenge \
		liblcms2.so:graphics/lcms2

USES=		compiler:c++11-lib libtool localbase:ldflags pathfix pkgconfig \
		tar:xz
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

PLIST_SUB=	LIBVERSION=1.0.${PORTVERSION:E}

CONFIGURE_ARGS=	--disable-tests --disable-werror --without-docs

.include <bsd.port.mk>
