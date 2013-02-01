# $FreeBSD$

PORTNAME=	libcdr
PORTVERSION=	0.0.10
CATEGORIES=	graphics devel
MASTER_SITES=	http://dev-www.libreoffice.org/src/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library and tools for parsing Corel Draw file format

LICENSE=	LGPL21 MPL GPLv2
LICENSE_COMB=	dual

LIB_DEPENDS=	icui18n:${PORTSDIR}/devel/icu \
		wpd-0.9:${PORTSDIR}/textproc/libwpd \
		wpg-0.2:${PORTSDIR}/graphics/libwpg \
		lcms2:${PORTSDIR}/graphics/lcms2

USE_XZ=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-werror
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes
USE_PKGCONFIG=	build

.include <bsd.port.mk>
