# New ports collection makefile for:	php_doc
# Date created:		Sun Apr 22 14:51:32 CEST 2001
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	php_doc
PORTVERSION=	1.0
CATEGORIES=	lang
MASTER_SITES=	http://www.php.net/${PHP_DISTDIR}/ \
		http://php.he.net/${PHP_DISTDIR}/ \
		http://www.php3.de/${PHP_DISTDIR}/ \
		http://au.php.net:81/${PHP_DISTDIR}/ \
		http://at.php.net/${PHP_DISTDIR}/ \
		http://br.php.net/${PHP_DISTDIR}/ \
		http://php.easydns.com/${PHP_DISTDIR}/ \
		http://www.php.cz/${PHP_DISTDIR}/ \
		http://php3.globe.de/${PHP_DISTDIR}/
DISTNAME=	manual

MAINTAINER=	dirk@FreeBSD.org

PHP_DISTDIR=	manual/${PHP_LANG}
DIST_SUBDIR=	php/${PHP_LANG}
NO_BUILD=	YES
NO_WRKSUBDIR=	YES

PHP_LANG?=	en
PHPDOCDIR=	${PREFIX}/share/doc/php

.if ${PHP_LANG} != en
PKGNAMEPREFIX=	${PHP_LANG}-
PLIST=		${PKGDIR}/pkg-plist.${PHP_LANG}
PHPDOCDIR=	${PREFIX}/share/doc/${PHP_LANG}-php
.endif

PLIST_SUB=	PHPDOCDIR=${PHPDOCDIR:S/^${PREFIX}\///}

do-install:
	@${MKDIR} ${PHPDOCDIR}
	@for i in ${WRKSRC}/*; do \
		${INSTALL_DATA} $$i ${PHPDOCDIR}; \
	done

.include <bsd.port.mk>
