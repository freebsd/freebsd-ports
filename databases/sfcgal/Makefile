# Created by: Loïc BARTOLETTI <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	sfcgal
PORTVERSION=	1.0.4
PORTREVISION=	2
CATEGORIES=	databases math graphics
MASTER_SITES=	http://github.com/Oslandia/${PORTNAME}/archive/v${PORTVERSION}.tar.gz?dummy=/

MAINTAINER=	coder@tuxfamily.org
COMMENT=	Wrapper library around CGAL for PostGIS

LICENSE=	GPLv2

LIB_DEPENDS=	libCGAL.so:${PORTSDIR}/math/cgal \
		libboost_system.so:${PORTSDIR}/devel/boost-libs \
		libgmp.so:${PORTSDIR}/math/gmp \
		libmpfr.so:${PORTSDIR}/math/mpfr

WRKSRC=		${WRKDIR}/SFCGAL-${PORTVERSION}

USES=		cmake compiler libtool
compiler_ARGS=	c++0x
USE_LDCONFIG=	yes

.include <bsd.port.mk>
