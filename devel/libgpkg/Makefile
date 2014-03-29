# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libgpkg
PORTVERSION=	0.9.16
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/luciad/libgpkg/get/ \
		LOCAL/sunpoet/${PORTNAME}
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	SQLite 3 extension of minimal OGC GeoPackage implementation

LICENSE=	APACHE20

OPTIONS_DEFINE=	GEOS
OPTIONS_DEFAULT=GEOS

USE_LDCONFIG=	yes
USES=		cmake tar:bzip2

WRKSRC=		${WRKDIR}/luciad-libgpkg-efe52f76ad35

GEOS_CMAKE_OFF=		-DGPKG_GEOS=OFF
GEOS_CMAKE_ON=		-DGPKG_GEOS=ON
GEOS_LIB_DEPENDS=	libgeos_c.so:${PORTSDIR}/graphics/geos

post-install:
	${INSTALL_LIB} ${WRKSRC}/gpkg/libgpkg.a ${STAGEDIR}${PREFIX}/lib/

.include <bsd.port.mk>
