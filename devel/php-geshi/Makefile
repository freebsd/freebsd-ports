# Created by: Eygene Ryabinkin <rea-fbsd@codelabs.ru>
# $FreeBSD$

PORTNAME=	geshi
DISTVERSION=	1.0.9.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	php-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Native PHP syntax highlighting engine

LICENSE=	GPLv2

USES=	php
USE_GITHUB=	yes
GH_ACCOUNT=	GeSHi
GH_PROJECT=	geshi-1.0

NO_BUILD=	yes
OPTIONS_DEFINE=	DOCS
NO_ARCH=	yes

EXTRACT_AFTER_ARGS=--exclude=.gitignore

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/php/geshi/
	${INSTALL_DATA} ${WRKSRC}/src/geshi.php ${STAGEDIR}${PREFIX}/lib/php/geshi/
	cd ${WRKSRC}/src/ && ${COPYTREE_SHARE} geshi ${STAGEDIR}${PREFIX}/lib/php/geshi/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
