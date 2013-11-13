# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	gearman
PORTVERSION=	1.1.2
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Gearman API

LICENSE=	PHP301

LIB_DEPENDS=	libgearman.so:${PORTSDIR}/devel/gearmand

CONFIGURE_ARGS=	--with-gearman
PHP_MODNAME=	${PORTNAME}
USE_PHP=	yes
USE_PHPEXT=	yes

.include <bsd.port.mk>
