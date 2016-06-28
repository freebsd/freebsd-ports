# Created by: Ditesh Shashikant Gathani <ditesh@gathani.org>
# $FreeBSD$

PORTNAME=	spl_types
PORTVERSION=	0.4.0
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DISTNAME=	SPL_Types-${PORTVERSION}
DIST_SUBDIR=	PECL

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	PECL extension of a collection of special typehandling classes

LICENSE=	PHP301

OPTIONS_DEFINE=	RE2C
RE2C_DESC=	Compile regular expression 2 C
RE2C_RUN_DEPENDS=	re2c:devel/re2c

USE_PHP=	spl
USES=		php:ext tar:tgz
IGNORE_WITH_PHP=	70

CONFIGURE_ARGS=	--enable-spl-types
CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
