# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	gearman
PORTVERSION=	1.1.2
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Gearman API

LICENSE=	PHP301

LIB_DEPENDS=	libgearman.so:devel/gearmand

USES=		tar:tgz
CONFIGURE_ARGS=	--with-gearman
PHP_MODNAME=	${PORTNAME}
USE_PHP=	yes
USE_PHPEXT=	yes
IGNORE_WITH_PHP=	70

.include <bsd.port.mk>
