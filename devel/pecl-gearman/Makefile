# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	gearman
PORTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	joneum@bsdproject.de
COMMENT=	Gearman API

LICENSE=	PHP301

LIB_DEPENDS=	libgearman.so:devel/gearmand

USES=		php:ext tar:tgz
CONFIGURE_ARGS=	--with-gearman
IGNORE_WITH_PHP=	70

.include <bsd.port.mk>
