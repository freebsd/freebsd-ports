# $FreeBSD$

PORTNAME=	android-tools-simpleperf
DISTVERSIONPREFIX=	android-
DISTVERSION=	m-preview-136
DISTVERSIONSUFFIX=	-g89a2254
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Android simpleperf tool

LICENSE=	APACHE20

BUILD_DEPENDS=	llvm-config${LLVM_VER}:${PORTSDIR}/devel/llvm${LLVM_VER}

USE_GITHUB=	yes
GH_ACCOUNT=	android:bionic,core jbeich
GH_PROJECT=	platform_bionic:bionic platform_system_core:core \
		platform_system_extras
GH_TAGNAME=	${DISTVERSIONFULL:C/-[0-9].*//}-232-gb4f2112:bionic \
		${DISTVERSIONFULL:C/-[0-9].*//}-868-gb81c410:core

USES=		compiler:c++11-lib uidfix
BUILD_WRKSRC=	${WRKSRC}/simpleperf
INSTALL_WRKSRC=	${BUILD_WRKSRC}
MAKEFILE=	${FILESDIR}/Makefile
MAKE_ENV=	BINDIR="${PREFIX}/bin" LLVM_CONFIG="llvm-config${LLVM_VER}"
ALL_TARGET=	all
LDFLAGS+=	-Wl,--as-needed # avoid overlinking (llvm deps)
PLIST_FILES=	bin/simpleperf

LLVM_VER?=	36 # XXX Move to DEFAULT_VERSIONS

OPTIONS_DEFINE=	TEST

TEST_BUILD_DEPENDS=googletest>=1.6.0:${PORTSDIR}/devel/googletest
TEST_ALL_TARGET=simpleperf_unit_test

post-extract:
# Adjust paths relative to extras
	@(cd ${WRKSRC_core} && ${COPYTREE_SHARE} . ${WRKSRC})
	@${MV} ${WRKSRC_bionic} ${WRKSRC}/bionic

pre-install-TEST-on:
	${BUILD_WRKSRC}/simpleperf_unit_test

.include <bsd.port.mk>
