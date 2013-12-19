# Created by: Wen Heping<wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tokyo_tyrant
PORTVERSION=	0.7.0
CATEGORIES=	databases pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Wrapper to the Tokyo Tyrant client library

LIB_DEPENDS=	libtokyotyrant.so:${PORTSDIR}/databases/tokyotyrant

USES=		pkgconfig
USE_PHP=	session
USE_PHP_BUILD=	spl
USE_PHPIZE=	yes
USE_PHPEXT=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
