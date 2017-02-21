# Created by: ports@nicandneal.net
# $FreeBSD$

PORTNAME=	nimble
PORTVERSION=	0.8.2
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	ports@nicandneal.net
COMMENT=	Package manager for the Nim programming language

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	nim:lang/nim
RUN_DEPENDS=	nim:lang/nim

USE_GITHUB=	yes
GH_ACCOUNT=	nim-lang

PLIST_FILES=	bin/nimble

do-build:
	cd ${WRKSRC} && nim c --parallelBuild=${MAKE_JOBS_NUMBER} --path:${LOCALBASE}/nim src/nimble

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nimble ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
