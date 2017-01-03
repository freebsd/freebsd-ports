# $FreeBSD$

PORTNAME=	libcdr
PORTVERSION=	0.1.3
PORTREVISION=	4
CATEGORIES=	graphics devel
MASTER_SITES=	LODEV
PKGNAMESUFFIX=	01

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library and tools for parsing Corel Draw file format

LICENSE=	LGPL21 MPL GPLv2
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/include/boost/optional.hpp:devel/boost-libs
LIB_DEPENDS=	libicui18n.so:devel/icu \
		librevenge-0.0.so:textproc/librevenge \
		liblcms2.so:graphics/lcms2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-tests --disable-werror --without-docs
USES=		compiler:c++11-lib libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-Wno-long-long

.include <bsd.port.mk>
