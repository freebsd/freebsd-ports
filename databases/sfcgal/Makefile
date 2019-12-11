# Created by: Loïc BARTOLETTI <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	sfcgal
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.7
PORTREVISION=	2
CATEGORIES=	databases math graphics

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	Wrapper library around CGAL for PostGIS

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libCGAL.so:math/cgal \
		libboost_system.so:devel/boost-libs \
		libgmp.so:math/gmp \
		libmpfr.so:math/mpfr

USES=		cmake compiler:c++0x libtool
USE_GITHUB=	yes
GH_ACCOUNT=	Oslandia
GH_PROJECT=	SFCGAL
USE_LDCONFIG=	yes

PLIST_SUB=	SHL3=${PORTVERSION} SHL1=${PORTVERSION:R:R}

.include <bsd.port.mk>
