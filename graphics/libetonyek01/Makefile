PORTNAME=	libetonyek
DISTVERSION=	0.1.12
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	LODEV/${PORTNAME}
PKGNAMESUFFIX=	01

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library to interpret and import Apple Keynote presentations
WWW=		https://wiki.documentfoundation.org/DLP/Libraries/libetonyek

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/mdds-${MDDS_VERSION}/mdds/global.hpp:devel/mdds \
		${LOCALBASE}/include/boost/any.hpp:devel/boost-libs \
		${LOCALBASE}/include/glm/glm.hpp:math/glm
LIB_DEPENDS=	librevenge-0.0.so:textproc/librevenge \
		liblangtag.so:devel/liblangtag

USES=		compiler:c++17-lang gnome libtool localbase pathfix pkgconfig \
		tar:xz
USE_CXXSTD=	c++17
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

MDDS_VERSION=	2.1

INSTALL_TARGET=	install-strip

PLIST_SUB=	LIBVERSION=1.0.${PORTVERSION:E}

CONFIGURE_ARGS=	--disable-tests --disable-werror --without-docs \
		--with-mdds=${MDDS_VERSION}

.include <bsd.port.mk>
