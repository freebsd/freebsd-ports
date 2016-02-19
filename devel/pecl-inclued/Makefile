# Created by: chinsan
# $FreeBSD$

PORTNAME=	inclued
PORTVERSION=	0.1.3
PORTEPOCH=	1
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Inclued gives you a Clue for PHP inclusion check

LICENSE=	PHP301

DEPRECATED=	${IGNORE}
EXPIRATION_DATE=2016-03-15

USES=		tar:tgz
USE_PHP=	yes
USE_PHPEXT=	yes
IGNORE_WITH_PHP=	55 56 70

CONFIGURE_ARGS=	--enable-inclued

.include <bsd.port.mk>
