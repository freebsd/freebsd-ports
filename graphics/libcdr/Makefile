# $FreeBSD$

PORTNAME=	libcdr
PORTVERSION=	0.0.14
CATEGORIES=	graphics devel
MASTER_SITES=	http://dev-www.libreoffice.org/src/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library and tools for parsing Corel Draw file format

LICENSE=	LGPL21 MPL GPLv2
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/include/boost/optional.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	libicui18n.so:${PORTSDIR}/devel/icu \
		libwpd-0.9.so:${PORTSDIR}/textproc/libwpd \
		libwpg-0.2.so:${PORTSDIR}/graphics/libwpg \
		liblcms2.so:${PORTSDIR}/graphics/lcms2

USE_XZ=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-werror --without-docs
USES=	pathfix pkgconfig
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-Wno-long-long

.include <bsd.port.mk>
