# Created by: Alex Kiesel <kiesel@schlund.de>
# $FreeBSD$

PORTNAME=	svn
PORTVERSION=	1.0.2
PORTREVISION=	2
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PECL extension to the libsvn library

LICENSE=	PHP301

LIB_DEPENDS=	libsvn_client-1.so:devel/subversion18

USES=		tar:tgz
USE_PHP=	yes
USE_PHPEXT=	yes
IGNORE_WITH_PHP=	70

.include <bsd.port.mk>
