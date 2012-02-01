# Ports collection makefile for:  pear-sqlite
# Date created:			  2004-04-30
# Whom:				  mat
#
# $FreeBSD$
#

PORTNAME=	sqlite
PORTVERSION=	1.0.3
CATEGORIES=	databases www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DISTNAME=	SQLite-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PECL classes to access sqlite databases in PHP 4

LICENSE=	PHP30

WRKSRC=		${WRKDIR}/SQLite-${PORTVERSION}
PKGMESSAGE=	${WRKDIR}/pkg-message

USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER=4
IGNORE_WITH_PHP=5 52

CONFIGURE_ARGS=	--with-sqlite

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.if !defined(NOPORTEXAMPLES)
PORTEXAMPLES=	sqlite.php
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/ ${DOCSDIR}/tests/
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/tests/* ${DOCSDIR}/tests/
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/sqlite.php ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
