# Created by: Volodymyr Kostyrko <c.kworr@gmail.com>
# $FreeBSD$

PORTNAME=	scream
DISTVERSION=	0.1.0
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	c.kworr@gmail.com
COMMENT=	Break the silence operator

LICENSE=	PHP301

USE_PHP=	yes
USE_PHPEXT=	yes

test: build
	@(cd ${WRKSRC} && ${MAKE} test)

NO_STAGE=	yes
.include <bsd.port.mk>
