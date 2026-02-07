PORTNAME=	msbuild
DISTVERSIONPREFIX=	v
DISTVERSION=	15.8-preview
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/mono/msbuild/releases/download/0.06/:bootstrap
DISTFILES=	mono_msbuild_xplat-master-3c930fa8.zip:bootstrap

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Build platform for .NET and Visual Studio
WWW=		https://github.com/Microsoft/msbuild

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash

USES=		mono:nuget shebangfix

NUGET_FEEDS=	DOTNET_CORE NUGET ROSLYN ROSLYN_TOOLS SYMREADER_CONVERTER
NUGET_LAYOUT=	dotnet

USE_GITHUB=	yes
GH_ACCOUNT=	mono
GH_TAGNAME=	0.06
SHEBANG_FILES=	*.sh artifacts/mono-msbuild/msbuild build.sh build/*.sh

MAKE_ENV=	GIT_COMMIT=3c930fa8721935cf0e381fd349f6f50cf2bc223d
ALL_TARGET=	all-mono
TEST_TARGET=	test-mono

post-extract:
	${MKDIR} ${WRKSRC}/artifacts
	${MV} ${WRKDIR}/msbuild ${WRKSRC}/artifacts/mono-msbuild

pre-configure:
	${REINPLACE_CMD} -e s/%%MAKE_JOBS_NUMBER%%/${MAKE_JOBS_NUMBER}/ \
		${WRKSRC}/build/build.sh \
		${WRKSRC}/Directory.Build.rsp

do-build:
	(cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} ./build/build.sh -host mono -configuration Release -skipTests build)

do-install:
	(cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} DESTDIR=${STAGEDIR} PATH=${WRKSRC}/artifacts/mono-msbuild:$$PATH ./install-mono-prefix.sh ${PREFIX})

do-test:
	(cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} ./build/build.sh -host mono -configuration Release build)

.include <bsd.port.mk>
