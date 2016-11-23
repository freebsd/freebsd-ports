# Created by: Loïc BARTOLETTI <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	sfcgal
PORTVERSION=	1.3.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	databases math graphics

MAINTAINER=	coder@tuxfamily.org
COMMENT=	Wrapper library around CGAL for PostGIS

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libCGAL.so:math/cgal \
		libboost_system.so:devel/boost-libs \
		libgmp.so:math/gmp \
		libmpfr.so:math/mpfr

USE_GITHUB=	yes
GH_ACCOUNT=	Oslandia
GH_PROJECT=	SFCGAL

USES=		cmake compiler libtool
compiler_ARGS=	c++0x
USE_LDCONFIG=	yes

.include <bsd.port.mk>
