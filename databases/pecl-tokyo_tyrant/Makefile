# Ports collection makefile for:	pecl-tokyo_tyrant
# Date created:				Feb 20, 2011
# Whom:					Wen Heping<wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tokyo_tyrant
PORTVERSION=	0.6.0
CATEGORIES=	databases pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Wrapper to the Tokyo Tyrant client library

LIB_DEPENDS=	tokyotyrant.3:${PORTSDIR}/databases/tokyotyrant

IGNORE_WITH_PHP=4

USE_PHP=	session
USE_PHP_BUILD=	spl
USE_PHPIZE=	yes
USE_PHPEXT=	yes

.include <bsd.port.mk>
