# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	weakref
PORTVERSION=	0.2.6
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DISTNAME=	Weakref-${PORTVERSION}
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PECL Weakref extension

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php:ext tar:tgz
IGNORE_WITH_PHP=	70

CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
