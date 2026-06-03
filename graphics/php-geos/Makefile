PORTNAME=	geos
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	graphics
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PHP bindings for GEOS
WWW=		https://git.osgeo.org/gitea/geos/php-geos

LICENSE=	LGPL21 MIT
LICENSE_COMB=	multi
LICENSE_FILE_LGPL21=	${WRKSRC}/LGPL-2
LICENSE_FILE_MIT=	${WRKSRC}/MIT-LICENSE

BUILD_DEPENDS=	swig:devel/swig
LIB_DEPENDS=	libgeos_c.so:graphics/geos

USES=		localbase:ldflags php:ext

USE_GITHUB=	yes
GH_ACCOUNT=	libgeos
GH_PROJECT=	php-geos
GH_TAGNAME=	dfe1ab1

.include <bsd.port.mk>
