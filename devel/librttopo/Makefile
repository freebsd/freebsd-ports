# $FreeBSD$

PORTNAME=	librttopo
DISTVERSION=	1.1.0
CATEGORIES=	devel geography
MASTER_SITES=	http://download.osgeo.org/librttopo/src/

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	RT Topology Library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgeos_c.so:graphics/geos

USES=		libtool localbase
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

INSTALL_TARGET=install-strip

PLIST_SUB=	SHL3=${PORTVERSION} SHL1=${PORTVERSION:R:R}

.include <bsd.port.mk>
