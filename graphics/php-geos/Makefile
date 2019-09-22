# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	geos
PORTVERSION=	1.0.0
CATEGORIES=	graphics
MASTER_SITES=	https://git.osgeo.org/gogs/geos/php-geos/archive/ \
		LOCAL/sunpoet/${PKGNAMEPREFIX}${PORTNAME}
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}
DISTNAME=	${DISTVERSION}
DIST_SUBDIR=	php-${PORTNAME}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PHP bindings for GEOS

LICENSE=	LGPL21 MIT
LICENSE_COMB=	multi
LICENSE_FILE_LGPL21=	${WRKSRC}/LGPL-2
LICENSE_FILE_MIT=	${WRKSRC}/MIT-LICENSE

BUILD_DEPENDS=	swig3.0:devel/swig30
LIB_DEPENDS=	libgeos_c.so:graphics/geos

USES=		localbase:ldflags php:ext
IGNORE_WITH_PHP=	74

WRKSRC=		${WRKDIR}/php-${PORTNAME}

.include <bsd.port.mk>
