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
LIB_DEPENDS=	icui18n:${PORTSDIR}/devel/icu \
		wpd-0.9:${PORTSDIR}/textproc/libwpd \
		wpg-0.2:${PORTSDIR}/graphics/libwpg \
		lcms2:${PORTSDIR}/graphics/lcms2

USE_XZ=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-werror --without-docs
USES=	pathfix pkgconfig
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-Wno-long-long

NO_STAGE=	yes
.include <bsd.port.mk>
