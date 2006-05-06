# New ports collection makefile for:	phpbt
# Date created:				28 November 2004
# Whom:					Wes Peters <wes@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	phpbt
PORTVERSION=	1.0.1
CATEGORIES?=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	wes@FreeBSD.org
COMMENT=	Bug-tracking system developed in PHP

RUN_DEPENDS=	${LOCALBASE}/share/pear/DB.php:${PORTSDIR}/databases/pear-DB

.if !defined(WITHOUT_PHP_DEPENDS)
USE_PHP=	ctype pcre posix session tokenizer xml zlib
.endif

NO_BUILD=	YES
PHPBT=		www/data-dist/phpbt
PLIST_SUB=	PHPBT=${PHPBT}

do-install:
	-${MKDIR} ${PREFIX}/${PHPBT}
	@(cd ${WRKSRC} && ${CP} -R * ${PREFIX}/${PHPBT})
	@${CHOWN} -R www:www ${PREFIX}/${PHPBT}

post-install:
	@${CAT} ${PKGMESSAGE} | \
	${SED} -e 's|%%PREFIX%%|${PREFIX}|' | \
	${SED} -e 's|%%PHPBT%%|${PHPBT}|'

.include <bsd.port.mk>
