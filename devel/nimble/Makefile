PORTNAME=	nimble
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.1
CATEGORIES=	devel

MAINTAINER=	ports@nicandneal.net
COMMENT=	Package manager for the Nim programming language

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

BUILD_DEPENDS=	nim:lang/nim
RUN_DEPENDS=	nim:lang/nim

USE_GITHUB=	yes
GH_ACCOUNT=	nim-lang
GH_TAGNAME=	d13f3b8

PLIST_FILES=	bin/nimble

do-build:
	@cd ${WRKSRC} && nim c -d:release --noNimblePath --parallelBuild=${MAKE_JOBS_NUMBER} --path:${LOCALBASE}/nim --nimcache:${WRKSRC}/nimcache src/nimble

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nimble ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
