# Created by: chinsan <chinsan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bcompiler
PORTVERSION=	1.0.2
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Bytecode compiler extension

LICENSE=	PHP202

USES=		php:ext tar:tgz
USE_PHP=	bz2:build
IGNORE_WITH_PHP=56 70

CONFIGURE_ARGS=	--enable-bcompiler

.include <bsd.port.mk>
