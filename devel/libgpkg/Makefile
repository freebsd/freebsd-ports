# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libgpkg
PORTVERSION=	0.9.18
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/luciad/libgpkg/get/${PORTVERSION}.tar.bz2?dummy=/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	SQLite 3 extension of minimal OGC GeoPackage implementation

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	fails to link: cc: Internal error: Segmentation fault (program ld)

OPTIONS_DEFINE=	GEOS
OPTIONS_DEFAULT=GEOS

USE_LDCONFIG=	yes
USES=		cmake tar:bzip2

PLIST_SUB=	PORTVERSION=${PORTVERSION}
WRKSRC=		${WRKDIR}/luciad-libgpkg-c56e3708453e

GEOS_CMAKE_OFF=		-DGPKG_GEOS=OFF
GEOS_CMAKE_ON=		-DGPKG_GEOS=ON
GEOS_LIB_DEPENDS=	libgeos_c.so:graphics/geos

post-install:
	${INSTALL_DATA} ${WRKSRC}/gpkg/libgpkg.a ${STAGEDIR}${PREFIX}/lib/

.include <bsd.port.mk>
