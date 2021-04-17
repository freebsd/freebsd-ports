# Created by: Loïc BARTOLETTI <lbartoletti@FreeBSD.org>

PORTNAME=	sfcgal
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.10
CATEGORIES=	databases math graphics

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Wrapper library around CGAL for PostGIS

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cgal>0:math/cgal
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libgmp.so:math/gmp \
		libmpfr.so:math/mpfr

USES=		cmake compiler:c++14-lang
USE_GITLAB=	yes
GL_ACCOUNT=	Oslandia
GL_PROJECT=	SFCGAL
GL_COMMIT=	8ec8641f0750e0fa78d70ffb5a90c3cab94e03d9
USE_LDCONFIG=	yes

PLIST_SUB=	SHL3=${PORTVERSION} SHL1=${PORTVERSION:R:R}

.include <bsd.port.mk>
