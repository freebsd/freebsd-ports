# $FreeBSD$

PORTNAME=	android-tools-simpleperf
DISTVERSIONPREFIX=	android-
DISTVERSION=	n-preview-1-116
DISTVERSIONSUFFIX=	-gea4a5a4
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Android simpleperf tool

LICENSE=	APACHE20 PD
LICENSE_COMB=	multi
LICENSE_FILE_PD=	${WRKSRC}/lzma/NOTICE

BUILD_DEPENDS=	llvm-config${LLVM_VER}:devel/llvm${LLVM_VER}

USE_GITHUB=	yes
GH_ACCOUNT=	android:bionic,core jbeich:DEFAULT,lzma
GH_PROJECT=	platform_bionic:bionic platform_system_core:core \
		platform_system_extras platform_external_lzma:lzma
GH_MYTAG=	${DISTVERSIONPREFIX}${DISTVERSION:C/-[0-9]*$//}
GH_TAGNAME=	${GH_MYTAG}-249-g5f1de52:bionic \
		${GH_MYTAG}-554-g371e7ea170d7:core \
		${GH_MYTAG}-6-ge43f249:lzma

USES=		compiler:c++11-lib uidfix
BUILD_WRKSRC=	${WRKSRC}/simpleperf
INSTALL_WRKSRC=	${BUILD_WRKSRC}
TEST_WRKSRC=	${BUILD_WRKSRC}
MAKEFILE=	${FILESDIR}/Makefile
MAKE_ENV=	BINDIR="${PREFIX}/bin" LLVM_CONFIG="llvm-config${LLVM_VER}"
ALL_TARGET=	all
TEST_TARGET=	test
LDFLAGS+=	-Wl,--as-needed # avoid overlinking (llvm deps)
PLIST_FILES=	bin/simpleperf

LLVM_VER?=	38 # XXX Move to DEFAULT_VERSIONS

OPTIONS_DEFINE=	TEST

TEST_BUILD_DEPENDS=	googletest>=1.6.0:devel/googletest
TEST_ALL_TARGET=	simpleperf_test

post-extract:
# Adjust paths relative to extras
	@(cd ${WRKSRC_core} && ${COPYTREE_SHARE} . ${WRKSRC})
	@${MV} ${WRKSRC_bionic} ${WRKSRC}/bionic
	@${MV} ${WRKSRC_lzma} ${WRKSRC}/lzma

post-patch:
# XXX C++ exception with description "regex_error" thrown in the test body.
	@if [ ${OPSYS} = FreeBSD -a ${OSREL:R} -lt 10 ]; then \
		${REINPLACE_CMD} -Ee '/^TEST/\
			s/ (LOG|PLOG|UNIMPLEMENTED)/ DISABLED_\1/' \
		${WRKSRC}/base/logging_test.cpp; \
	fi

pre-install-TEST-on: do-test

.include <bsd.port.mk>
