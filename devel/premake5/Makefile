# $FreeBSD$

PORTNAME=	premake
DISTVERSIONPREFIX=	v
DISTVERSION=	5.0.0
CATEGORIES=	devel
PKGNAMESUFFIX=	5

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Build script creation tool

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=	aarch64 amd64 i386

USES=		dos2unix gmake

USE_GITHUB=	yes
GH_PROJECT=	premake-core
GH_TAGNAME=	09ee833

MAKE_ARGS=	CC="${CC}" \
		CXX="${CXX}"
DOS2UNIX_FILES=	tests/_tests.lua
PLIST_FILES=	bin/premake5

MAKEFILE=	Bootstrap.mak
ALL_TARGETS=	bsd

do-build:
	cd ${WRKSRC} && ${GMAKE} -f Bootstrap.mak bsd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/release/premake5 ${STAGEDIR}${PREFIX}/bin

do-test:
	cd ${WRKSRC}/tests && ./test

.include <bsd.port.mk>
