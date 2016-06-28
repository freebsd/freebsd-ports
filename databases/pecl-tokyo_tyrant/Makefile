# Created by: Wen Heping<wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tokyo_tyrant
PORTVERSION=	0.7.0
CATEGORIES=	databases pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Wrapper to the Tokyo Tyrant client library

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	Does not build

LIB_DEPENDS=	libtokyotyrant.so:databases/tokyotyrant

USES=		php:ext pkgconfig tar:tgz
USE_PHP=	session:build
IGNORE_WITH_PHP=	70

.include <bsd.port.mk>
