# Created by: John Chen <johnpupu@gmail.com>
# $FreeBSD$

PORTNAME=	APCu
PORTVERSION=	4.0.10
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DISTNAME=	${PORTNAME:tl}-${PORTVERSION}
DIST_SUBDIR=	PECL

MAINTAINER=	johnpupu@gmail.com
COMMENT=	APC User Caching

LICENSE=	PHP301

CONFLICTS=	pecl-APC-[0-9]*

CFLAGS+=	-I${LOCALBASE}/include
USE_PHP=	yes
USE_PHP_BUILD=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes
IGNORE_WITH_PHP=	70
USES=		tar:tgz
PHP_MODNAME=	${PORTNAME:tl}
WRKSRC=		${WRKDIR}/${PORTNAME:tl}-${PORTVERSION}

.include <bsd.port.mk>
