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

USES=		cmake:insource compiler:c11 tar:bzip2

USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/luciad-libgpkg-c56e3708453e

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	GEOS
OPTIONS_DEFAULT=GEOS

GEOS_CMAKE_BOOL=	GPKG_GEOS
GEOS_LIB_DEPENDS=	libgeos_c.so:graphics/geos

post-install:
	${INSTALL_DATA} ${WRKSRC}/gpkg/libgpkg.a ${STAGEDIR}${PREFIX}/lib/

.include <bsd.port.mk>
