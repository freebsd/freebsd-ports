# $FreeBSD$

PORTNAME=	premake5
DISTVERSIONPREFIX=	v
DISTVERSION=	5.0.0
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Build script creation tool

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=	aarch64 amd64 i386

USES=		dos2unix gmake
MAKE_ARGS=	CC="${CC}" \
		CXX="${CXX}"

USE_GITHUB=	yes
GH_ACCOUNT=	premake
GH_PROJECT=	premake-core
GH_TAGNAME=	09ee833

DOS2UNIX_FILES=	tests/_tests.lua
PLIST_FILES=	bin/premake5

do-build:
	cd ${WRKSRC} && ${GMAKE} -f Bootstrap.mak bsd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/release/premake5 ${STAGEDIR}${PREFIX}/bin

do-test:
	cd ${WRKSRC}/tests && ./test

.include <bsd.port.mk>
