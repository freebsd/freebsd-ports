# Created by: JoeHorn <joehorn@gmail.com>
# $FreeBSD$

PORTNAME=	adodb-ext
PORTVERSION=	5.04
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://phplens.com/lens/dl/
PKGNAMEPREFIX=	php-
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//}

MAINTAINER=	joehorn@gmail.com
COMMENT=	ADOdb Extension

WRKSRC=		${WRKDIR}/adodb-${PORTVERSION:S/.//}

USE_PHP=	yes
USE_PHPIZE=	yes
DEFAULT_PHP_VER=53
USE_ZIP=	yes

CONFIGURE_ARGS=		--with-php-config=${PREFIX}/bin/php-config \
			--prefix=${PREFIX}/lib/php/${PHP_EXT_DIR}
SUB_FILES=	pkg-message
PLIST_SUB=	PHP_EXT_DIR=${PHP_EXT_DIR}
USE_DOS2UNIX=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PHP_VER} == "5"
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-php54-adodb.c
.elif ${PHP_VER} != "52"
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-adodb.c
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
