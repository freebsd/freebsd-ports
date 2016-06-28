# Created by: Elias Mandouvalos <ocean@mail.gr>
# $FreeBSD$

PORTNAME=	runkit
PORTVERSION=	1.0.4
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PECL extension to modify constants, user-defined functions, and classes

LICENSE=	PHP30

USES=		php:ext tar:tgz
IGNORE_WITH_PHP=	70

CONFIGURE_ARGS=	--enable-runkit=classkit

.include <bsd.port.mk>
