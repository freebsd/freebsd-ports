# $FreeBSD$

PORTNAME=	android-tools-simpleperf
DISTVERSIONPREFIX=	android-
DISTVERSION=	7.1.2_r17
PORTREVISION=	9
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Android simpleperf tool

LICENSE=	APACHE20

BUILD_DEPENDS=	llvm-config${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}

USE_GITHUB=	yes
GH_TUPLE=	jbeich:platform_system_extras:${DISTVERSIONFULL} \
		aosp-mirror:platform_system_core:${DISTVERSIONFULL}:core \
		aosp-mirror:platform_bionic:${DISTVERSIONFULL}:bionic/bionic

USES=		compiler:c++11-lib ncurses uidfix
BUILD_WRKSRC=	${WRKSRC}/simpleperf
INSTALL_WRKSRC=	${BUILD_WRKSRC}
TEST_WRKSRC=	${BUILD_WRKSRC}
MAKEFILE=	${FILESDIR}/Makefile
MAKE_ENV=	BINDIR="${PREFIX}/bin" LLVM_CONFIG="llvm-config${LLVM_DEFAULT}"
ALL_TARGET=	all
TEST_TARGET=	test
LDFLAGS+=	-Wl,--as-needed # avoid overlinking (llvm deps)
PLIST_FILES=	bin/simpleperf

OPTIONS_DEFINE=	TEST

TEST_BUILD_DEPENDS=	googletest>=1.6.0:devel/googletest
TEST_ALL_TARGET=	simpleperf_test

post-extract:
# Adjust paths relative to extras
	@(cd ${WRKSRC_core} && ${COPYTREE_SHARE} . ${WRKSRC})

pre-install-TEST-on: do-test

.include <bsd.port.mk>
