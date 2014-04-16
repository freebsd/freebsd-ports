# Created by: Ditesh Shashikant Gathani <ditesh@gathani.org>
# $FreeBSD$

PORTNAME=	spl_types
PORTVERSION=	0.4.0
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DISTNAME=	SPL_Types-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	5u623l20@gmail.com
COMMENT=	PECL extension of a collection of special typehandling classes

LICENSE=	PHP301

OPTIONS_DEFINE=	RE2C
RE2C_DESC=	Compile regular expression 2 C
RE2C_RUN_DEPENDS=	re2c:${PORTSDIR}/devel/re2c

USE_PHP=	spl
#USE_PHP_BUILD=	yes
USE_PHPEXT=	yes
USES=		tar:tgz

CONFIGURE_ARGS=	--enable-spl-types
CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
