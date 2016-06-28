# Created by: Alexander Zhuravlev <zaa@zaa.pp.ru>
# $FreeBSD$

PORTNAME=	operator
PORTVERSION=	0.3
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHP extension that provides operator overloading for PHP objects

LICENSE=	PHP30

USES=		php:ext tar:tgz
IGNORE_WITH_PHP=	56 70

post-extract::
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
