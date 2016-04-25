# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	igbinary
PORTVERSION=	1.2.1
CATEGORIES=	converters
MASTER_SITES=	http://pecl.php.net/get/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Replacement for the standard PHP serializer

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc64=	does not build

IGNORE_WITH_PHP=70
USE_PHP=	session
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes
USE_PHPIZE=	yes
USES=		tar:tgz

.include <bsd.port.mk>
