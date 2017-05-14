# $FreeBSD$

PORTNAME=	unicorn
PORTVERSION=	1.0.1
CATEGORIES=	emulators

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Unicorn CPU emulator framework

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	cmocka>0:sysutils/cmocka

BROKEN_powerpc64=	fails to compile: cc1: error: unrecognized command line option "-Wno-logical-op-parentheses"

USE_GITHUB=	yes
GH_ACCOUNT=	unicorn-engine

USES=		gmake python:2.7,build
USE_LDCONFIG=	yes
MAKE_ENV=	INSTALL_LIB="${INSTALL_LIB}" \
		UNICORN_QEMU_FLAGS=--python=${PYTHON_CMD} \
		SMP_MFLAGS=-j${MAKE_JOBS_NUMBER} \
		V=1
TEST_TARGET=	test
TEST_WRKSRC=	${WRKSRC}/tests/unit
_MAKE_JOBS=	# MAKE_JOBS_NUMBER is passed via MAKE_ENV
# Optimization breaks runtime,
# see https://github.com/unicorn-engine/unicorn/issues/356
# and https://github.com/unicorn-engine/unicorn/issues/689
CFLAGS:=	${CFLAGS:C/-O[1-9]/-O0/g}

.include <bsd.port.mk>
