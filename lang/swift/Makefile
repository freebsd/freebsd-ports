# $FreeBSD$

PORTNAME=	swift
PORTVERSION=	3.1.1
DISTVERSIONPREFIX=	swift-
DISTVERSIONSUFFIX=	-RELEASE
PORTREVISION=	9
CATEGORIES=	lang

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Swift programing language

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/swift/LICENSE.txt

BROKEN=		fails to build

BUILD_DEPENDS=	cmake:devel/cmake \
		bash:shells/bash \
		swig3.0:devel/swig30 \
		binutils>=2.25.1:devel/binutils
LIB_DEPENDS=	libicudata.so:devel/icu \
		libuuid.so:misc/e2fsprogs-libuuid \
		libobjc.so:lang/libobjc2

REL_SNAP=	2017-04-22-a
USE_GITHUB=	yes
BINARY_ALIAS=	swig=swig3.0 python=${PYTHON_CMD}

GH_ACCOUNT=	apple:DEFAULT,llvm,clang,dispatch,lldb,cmark,llbuild,swiftpm,xctest,xcfound
GH_PROJECT=	swift:DEFAULT swift-llvm:llvm swift-clang:clang swift-lldb:lldb \
		swift-cmark:cmark swift-llbuild:llbuild swift-package-manager:swiftpm \
		swift-corelibs-xctest:xctest swift-corelibs-foundation:xcfound \
		swift-corelibs-libdispatch:dispatch
GH_TAGNAME=	swift-${PORTVERSION}-RELEASE:llbuild,swiftpm,xctest,xcfound,dispatch
GH_SUBDIR=	llvm:llvm clang:clang lldb:lldb cmark:cmark llbuild:llbuild \
		swiftpm:swiftpm swift-corelibs-xctest:xctest \
		swift-corelibs-foundation:xcfound \
		swift-corelibs-libdispatch:dispatch

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		autoreconf:build compiler:c++14-lang libtool localbase:ldflags iconv libedit \
		ninja perl5 pkgconfig python:build sqlite

USE_GNOME=	libxml2
USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	amd64
CONFLICTS_BUILD=	googletest
LDFLAGS+=	-lobjc

OPTIONS_DEFINE=	DOCS
DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx
DOCS_CMAKE_BOOL=	SWIFT_INCLUDE_DOCS

PORTDOCS=	*

STRIP_FILES=	bin/sil-func-extractor bin/sil-nm bin/sil-opt \
		bin/sil-passpipeline-dumper bin/swift \
		bin/swift-api-digester bin/swift-build-tool \
		bin/swift-demangle bin/swift-ide-test \
		bin/swift-llvm-opt bin/swift-reflection-dump \
		bin/swift-remoteast-test lib/swift/freebsd/libswiftCore.so \
		lib/swift/freebsd/libswiftGlibc.so \
		lib/swift/freebsd/libswiftRemoteMirror.so \
		lib/swift/freebsd/libswiftSwiftOnoneSupport.so

.include <bsd.port.pre.mk>

CC_ONLY=	${CC:C/.*\///}
CPP_ONLY=	${CPP:C/.*\///}
CXX_ONLY=	${CXX:C/.*\///}

post-extract:
	@${MKDIR} ${WRKSRC}
	@${MV} ${WRKDIR}/${PORTNAME}-${PORTNAME}-${PORTVERSION}-RELEASE ${WRKSRC}/swift

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/swift/cmake/modules/SwiftSharedCMakeConfig.cmake
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%CPP_ONLY%%|${CPP_ONLY}|g' \
		-e 's|%%CC_ONLY%%|${CC_ONLY}|g' \
		-e 's|%%CXX_ONLY%%|${CXX_ONLY}|g' \
		${WRKSRC}/swift/utils/build-presets.ini \
		${WRKSRC}/swift/utils/build-script-impl

do-build:
	@${MKDIR} ${STAGEDIR}${PREFIX}
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} \
		./swift/utils/build-script --preset=mixin_freebsd_installation \
		-j ${MAKE_JOBS_NUMBER} \
		install_destdir=${STAGEDIR} \
		-- \
		${EXTRA_FLAGS} \
		--skip-build-llvm=1 \
		--install_prefix=${PREFIX} \
		--install_destdir=${STAGEDIR} \
		--verbose-build=1 \
		--install-llbuild=1 \
		--skip-test-llbuild=1
	@${RM} /var/run/libuuid/clock.txt /var/run/libuuid/request /var/run/libuuid/uuidd.pid

do-install:
	${MV} ${STAGEDIR}${PREFIX}/share/man/man1/swift.1 ${STAGEDIR}${PREFIX}/man/man1/swift.1
	${RM} -r ${STAGEDIR}${PREFIX}/share/man
	${GZIP_CMD} ${STAGEDIR}${PREFIX}/man/man1/swift.1
.for FILE in ${STRIP_FILES}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${FILE}
.endfor

do-install-DOCS-on:
	cd ${WRKSRC}/build/Ninja-ReleaseAssert+stdlib-Release/swift-freebsd-x86_64/docs/html ; \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
