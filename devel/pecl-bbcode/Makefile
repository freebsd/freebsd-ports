# Created by: Ditesh Shashikant Gathani <ditesh@gathani.org>
# $FreeBSD$

PORTNAME=	bbcode
PORTVERSION=	1.0.2
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A PECL extension which allows quick and efficient BBCode Parsing

LICENSE=	PHP301 BSD
LICENSE_COMB=	multi

USE_PHP=	yes
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER=53
IGNORE_WITH_PHP=5

CONFIGURE_ARGS=	--enable-bbcode

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's/#include <malloc.h>/\/\/#include <malloc.h>/g' ${WRKSRC}/lib/bbcode2.c

.include <bsd.port.mk>
