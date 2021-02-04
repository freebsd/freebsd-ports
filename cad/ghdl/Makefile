# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ghdl
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	cad

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	38025814efbba57d7527f37b16847b114815ab62.patch:-p1 # fixes https://github.com/ghdl/ghdl/issues/1627

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	GNU VHDL simulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.md

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libmpc.so:math/mpc
TEST_DEPENDS=	bash:shells/bash

USES=		ada:run gmake shebangfix
SHEBANG_FILES=	testsuite/testsuite.sh
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

LLVMVER=	${LLVM_DEFAULT}

CONFIGURE_ARGS=	--disable-libghdl

OPTIONS_SINGLE=		BACKEND
OPTIONS_SINGLE_BACKEND=	MCODE LLVM
OPTIONS_DEFAULT=	LLVM
OPTIONS_SUB=		yes

MCODE_DESC=		Use the MCODE backend
# MCODE is enabled by default and doesn't require any configuration options

LLVM_DESC=		Code generator is LLVM
LLVM_USES=		libedit ncurses
LLVM_CONFIGURE_ON=	--with-llvm-config=${LOCALBASE}/bin/llvm-config${LLVM_DEFAULT}
LLVM_BUILD_DEPENDS=	llvm-config${LLVMVER}:devel/llvm${LLVMVER}
LLVM_RUN_DEPENDS=	llc${LLVMVER}:devel/llvm${LLVMVER}

post-install-MCODE-on:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/ghdl \
		${STAGEDIR}${PREFIX}/lib/libghdlvpi.so

post-install-LLVM-on:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/ghdl \
		${STAGEDIR}${PREFIX}/bin/ghdl1-llvm \
		${STAGEDIR}${PREFIX}/lib/libghdlvpi.so

do-test:
	@cd ${WRKSRC}/testsuite && \
		${SETENV} ${MAKE_ENV} GHDL=${STAGEDIR}${PREFIX}/bin/ghdl ${SH} testsuite.sh

.include <bsd.port.mk>
