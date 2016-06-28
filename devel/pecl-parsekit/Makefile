# Created by: Sébastien Santoro <dereckson@gmail.com>
# $FreeBSD$

PORTNAME=	parsekit
PORTVERSION=	1.3.0
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	dereckson@gmail.com
COMMENT=	Extension for opcodes runtime analysis

LICENSE=	PHP301

USES=		php:ext
IGNORE_WITH_PHP=	56 70

CONFIGURE_ARGS=	--enable-parsekit
CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
