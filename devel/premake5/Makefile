PORTNAME=	premake
DISTVERSIONPREFIX=	v
DISTVERSION=	5.0.0-beta7
CATEGORIES=	devel
MASTER_SITES=	https://github.com/premake/premake-core/releases/download/${DISTVERSIONFULL}/
PKGNAMESUFFIX=	5
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Build script creation tool
WWW=		https://premake.github.io/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=	aarch64 amd64 armv7 i386 powerpc powerpc64 powerpc64le

USES=		dos2unix gmake zip
DOS2UNIX_FILES=	tests/_tests.lua tests/test src/host/*.c src/host/premake.h

MAKEFILE=	Bootstrap.mak
MAKE_ARGS=	CC="${CC}" \
		CXX="${CXX}"
ALL_TARGET=	bsd

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/premake5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/release/premake5 ${STAGEDIR}${PREFIX}/bin

do-test:
	cd ${WRKSRC}/tests && ./test

.include <bsd.port.mk>
