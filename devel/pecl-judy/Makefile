# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	judy
PORTVERSION=	1.0.0
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DISTNAME=	Judy-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	PHP Judy implements sparse dynamic arrays

LICENSE=	PHP301

RUN_DEPENDS=	Judy>=0:${PORTSDIR}/devel/judy
BUILD_DEPENDS=	Judy>=0:${PORTSDIR}/devel/judy

CONFIGURE_ARGS=	--with-judy=${LOCALBASE}
USE_PHP=	yes
USE_PHPEXT=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
