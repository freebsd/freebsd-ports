# Created by: John Chen <johnpupu@gmail.com>
# $FreeBSD$

PORTNAME=	msgpack
PORTVERSION=	0.5.7
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	johnpupu@gmail.com
COMMENT=	Provides API for communicating with MessagePack serialization

LICENSE=	BSD3CLAUSE

BROKEN_powerpc64=	Does not build

USES=		php:ext tar:tgz
USE_PHP=	session:build
IGNORE_WITH_PHP=	70

.include <bsd.port.mk>
