# Created by: Eygene Ryabinkin <rea-fbsd@codelabs.ru>
# $FreeBSD$

PORTNAME=	geshi
DISTVERSION=	1_0_8_12
DISTVERSIONPREFIX=	RELEASE_
CATEGORIES=	devel
PKGNAMEPREFIX=	php5-

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
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/src/docs/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
