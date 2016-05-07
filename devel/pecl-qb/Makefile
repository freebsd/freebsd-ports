# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	qb
PORTVERSION=	2.4.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	PHP Accelerator designed mainly for graphic work

LICENSE=	PHP301

USE_PHP=	yes
USE_PHPEXT=	yes
USES=		tar:tgz
USE_GCC=	any
IGNORE_WITH_PHP=	70

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000034
LIB_DEPENDS+=	libmissing.so:math/libmissing
CONFIGURE_ARGS=	--with-libmissing=${LOCALBASE}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-libmissing
.endif

.include <bsd.port.post.mk>
