# Created by: Wes Peters <wes@FreeBSD.org>
# $FreeBSD$

PORTNAME=	phpbt
PORTVERSION=	1.0.1
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bug-tracking system developed in PHP

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${LOCALBASE}/share/pear/DB.php:databases/pear-DB@${PHP_FLAVOR}

.if !defined(WITHOUT_PHP_DEPENDS)
USE_PHP=	ctype pcre posix session tokenizer xml zlib
.endif

SHEBANG_FILES=	contrib/gnats-to-phpbt.py
NO_BUILD=	yes
NO_ARCH=	yes
PHPBT=		www/data-dist/phpbt
PLIST_SUB=	PHPBT=${PHPBT} WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"
SUB_FILES=	pkg-message
SUB_LIST=	PHPBT=${PHPBT}

OPTIONS_DEFINE=	GNATS
OPTIONS_DEFAULT=GNATS
OPTIONS_SUB=	yes

GNATS_DESC=	Install script to convert entries from GNATS
GNATS_USES=	python:2.7,run shebangfix

post-extract-GNATS-off:
	@${RM} ${WRKSRC}/contrib/gnats-to-phpbt.py

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PHPBT}
	@(cd ${WRKSRC} && ${CP} -R * ${STAGEDIR}${PREFIX}/${PHPBT})

.include <bsd.port.mk>
