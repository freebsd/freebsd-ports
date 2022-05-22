PORTNAME=	stellarsolver
DISTVERSION=	2.3
CATEGORIES=	astro

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Astrometric Plate Solver built on Astrometry.net and SEP

LICENSE=	GPLv3

LIB_DEPENDS=	libcfitsio.so:astro/cfitsio \
		libgsl.so:math/gsl \
		libwcs.so:astro/wcslib

USES=		cmake desktop-file-utils iconv ninja qt:5 pkgconfig 
USE_QT=		buildtools concurrent core gui qmake_build network widgets
USE_GITHUB=	yes
GH_ACCOUNT=	rlancaste

USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DBUILD_BATCH_SOLVER=on

.include <bsd.port.mk>
