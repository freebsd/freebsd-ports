# $FreeBSD$

PORTNAME=	unicorn
DISTVERSION=	1.0.2-rc3
CATEGORIES=	emulators

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Unicorn CPU emulator framework

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	cmocka>0:sysutils/cmocka

BROKEN_armv6=		fails to compile: 'tcg-target.h' file not found
BROKEN_armv7=		fails to compile: 'tcg-target.h' file not found
BROKEN_mips=		fails to compile: 'ICACHE' undeclared (first use in this function)
BROKEN_mips64=		fails to compile: 'ICACHE' undeclared (first use in this function)

USE_GITHUB=	yes
GH_ACCOUNT=	unicorn-engine

USES=		compiler:c11 gmake python:build
USE_LDCONFIG=	yes
BINARY_ALIAS=	python=${PYTHON_CMD}
MAKE_ENV=	INSTALL_LIB="${INSTALL_LIB}" \
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
