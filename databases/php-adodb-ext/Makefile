# New ports collection makefile for:	php-adodb-ext
# Date created:		29 July 2008
# Whom:			JoeHorn <joehorn@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	adodb-ext
PORTVERSION=	5.04
CATEGORIES=	databases
MASTER_SITES=	http://phplens.com/lens/dl/
PKGNAMEPREFIX=	php-
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//}

MAINTAINER=	joehorn@gmail.com
COMMENT=	ADOdb Extension

WRKSRC=		${WRKDIR}/adodb-${PORTVERSION:S/.//}

USE_PHP=	yes
USE_PHPIZE=	yes
USE_ZIP=	yes
DEFAULT_PHP_VER=	5
CONFIGURE_ARGS=		--with-php-config=${PREFIX}/bin/php-config \
			--prefix=${PREFIX}/lib/php/${PHP_EXT_DIR}
SUB_FILES=	pkg-message
PLIST_SUB=	PHP_EXT_DIR=${PHP_EXT_DIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
