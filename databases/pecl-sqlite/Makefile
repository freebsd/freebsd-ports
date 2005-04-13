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

MAINTAINER=	marcus@corp.grupos.com.br
COMMENT=	PECL classes to access sqlite databases

WRKSRC=		${WRKDIR}/SQLite-${PORTVERSION}
PKGMESSAGE=	${WRKDIR}/pkg-message

USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	sqlite

CONFIGURE_ARGS=	--with-sqlite

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

.include <bsd.port.pre.mk>

.if ${PHP_VER} == 5
IGNORE=		Please use databases/php${PHP_VER}-sqlite
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/tests
	@${INSTALL_DATA} ${WRKSRC}/CREDITS ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/tests/* ${DOCSDIR}/tests

	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/sqlite.php ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
