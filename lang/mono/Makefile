# Created by: Yukihiro Nakai <nakai@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mono
PORTVERSION=	4.8.1.0
DISTVERSIONPREFIX=	mono-
PORTREVISION=	2
CATEGORIES=	lang

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Open source implementation of .NET Development Framework

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser \
		bash:shells/bash
LIB_DEPENDS=	libinotify.so:devel/libinotify
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>=0:graphics/py-pillow

BROKEN_armv6=		fails to compile: mono/arch/arm/arm-codegen.h:947:10: fatal error: 'mono/arch/arm/arm_dpimacros.h' file not found
BROKEN_armv7=		fails to compile: mono/arch/arm/arm-codegen.h:947:10: fatal error: 'mono/arch/arm/arm_dpimacros.h' file not found
ONLY_FOR_ARCHS=		amd64 armv6 armv7 i386 powerpc

OPTIONS_DEFINE=		ACCEPTANCE_TESTS MONOLITE
OPTIONS_DEFAULT=	MONOLITE
ACCEPTANCE_TESTS_DESC=	Download and run the .Net acceptance tests
ACCEPTANCE_TESTS_DISTFILES=nuget.31.zip:nuget31
ACCEPTANCE_TESTS_GH_TUPLE=xamarin:benchmarker:97f618c:12/acceptance-tests/external/benchmarker \
			dotnet:coreclr:c7da48a:13/acceptance-tests/external/coreclr \
			dotnet:roslyn:322bd5b:14/acceptance-tests/external/roslyn
ACCEPTANCE_TESTS_MASTER_SITES=https://dotnetci.blob.core.windows.net/roslyn/:nuget31
ACCEPTANCE_TESTS_TEST_DEPENDS=bash:shells/bash \
			referenceassemblies-pcl>=4.6:lang/referenceassemblies-pcl
ACCEPTANCE_TESTS_VARS=	SHEBANG_FILES+=${WRKSRC}/acceptance-tests/external/roslyn/cibuild.sh
MONOLITE_DESC=		Use monolite to bootstrap mcs (otherwise use installed mcs)
MONOLITE_DISTFILES=	monolite-${MONOLITE_VERSION}-latest.tar.gz:monolite
MONOLITE_MASTER_SITES=	http://download.mono-project.com/monolite/:monolite

MONOLITE_VERSION=	156
USE_GITHUB=	yes
GH_TUPLE=	mono:Lucene.Net.Light:85978b7:1/external/Lucene.Net.Light \
		mono:Newtonsoft.Json:471c3e0:2/external/Newtonsoft.Json \
		mono:NuGet.BuildTasks:04bdab5:3/external/nuget-buildtasks \
		mono:aspnetwebstack:e77b12e:4/external/aspnetwebstack \
		mono:buildtools:9b6ee86:5/external/buildtools \
		mono:cecil:2b39856:6/external/cecil \
		mono:cecil:33d50b8:7/external/cecil-legacy \
		mono:ikdasm:e4deabf:8/external/ikdasm \
		mono:ikvm-fork:367864e:9/external/ikvm \
		mono:reference-assemblies:6c77197:10/external/binary-reference-assemblies \
		mono:rx:b29a4b0:11/external/rx

USES=		autoreconf bison compiler:c11 cpe gettext gmake iconv libtool pathfix \
		perl5 python shebangfix tar:bzip2
USE_GNOME=	glib20
USE_PERL5=	build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
SHEBANG_FILES=	scripts/mono-heapviz

CONFIGURE_ARGS=	--disable-dtrace
CONFIGURE_ENV=	ac_cv_header_sys_inotify_h=no

MAKE_ENV=	MONO_SHARED_DIR="${WRKDIR}" \
		INSTALL_STRIP_FLAG="${STRIP}" \
		TZ=UTC

TEST_TARGET=	check
TEST_WRKSRC=	${WRKSRC}/mono/tests

PORTSCOUT=	limit:^\d+\.\d+\.[1-9]\d*

LOCALBASE?=	/usr/local
.if !exists(${LOCALBASE}/bin/mcs)
OPTIONS_SLAVE=	MONOLITE
.endif

post-extract-MONOLITE-on:
	${MKDIR} ${WRKSRC}/mcs/class/lib
	${MV} ${WRKDIR}/monolite-${MONOLITE_VERSION}-latest ${WRKSRC}/mcs/class/lib/monolite

post-patch:
	${REINPLACE_CMD} -e 's|^#!/bin/bash|#!/usr/bin/env bash|g' \
		${WRKSRC}/scripts/mono-find-provides.in \
		${WRKSRC}/scripts/mono-find-requires.in \
		${WRKSRC}/scripts/mono-test-install
	${FIND} ${WRKSRC} -name '*.sh' | ${XARGS} ${REINPLACE_CMD} \
		-e 's|^#!/bin/bash|#!/bin/sh|g'
	${SED} 's/tarball/${PORTVERSION}/' ${WRKSRC}/mono/mini/Makefile.am.in \
		> ${WRKSRC}/mono/mini/Makefile.am

post-patch-ACCEPTANCE_TESTS-on:
	${REINPLACE_CMD} -E -e 's!(~/|/tmp/)!${WRKDIR}/!g' -e '/git clean/d' \
		${WRKSRC}/acceptance-tests/external/roslyn/cibuild.sh
	${TOUCH} ${WRKDIR}/nuget.31.zip

post-configure:
	${REINPLACE_CMD} -e 's|share\/man|man|g' \
		${WRKSRC}/mcs/jay/Makefile

do-test-ACCEPTANCE_TESTS-on:
	@(cd ${WRKSRC}/acceptance-tests; \
		${DO_MAKE_TEST} check-full IGNORE_BENCHMARKER_VERSION=1 IGNORE_CORECLR_VERSION=1 IGNORE_ROSLYN_VERSION=1)

.include <bsd.port.mk>
