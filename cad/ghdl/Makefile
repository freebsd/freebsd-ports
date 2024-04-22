PORTNAME=	ghdl
DISTVERSIONPREFIX=	v
DISTVERSION=	4.0.0
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	GNU VHDL simulator
WWW=		https://github.com/ghdl/ghdl

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.md

BROKEN_aarch64=	build breaks, see https://github.com/ghdl/ghdl/issues/2639

TEST_DEPENDS=	bash:shells/bash \
		${PYTHON_PKGNAMEPREFIX}pyTooling>=2.11.0:devel/py-pyTooling@${PY_FLAVOR}

USES=		ada:run gmake python:test shebangfix
SHEBANG_FILES=	testsuite/testsuite.sh
USE_LDCONFIG=	yes

USE_GITHUB=	yes

GNU_CONFIGURE=	yes

LLVMVER=	15 # last supported version, see https://github.com/ghdl/ghdl/blob/master/configure#L317

OPTIONS_DEFINE=		SYNTH
OPTIONS_SINGLE=		BACKEND
OPTIONS_SINGLE_BACKEND=	MCODE LLVM
OPTIONS_DEFAULT=	LLVM SYNTH
OPTIONS_SUB=		yes

MCODE_DESC=		Use the MCODE backend
# MCODE is enabled by default and doesn't require any configuration options

LLVM_DESC=		Code generator is LLVM
LLVM_USES=		ncurses
LLVM_CONFIGURE_ON=	--with-llvm-config=${LOCALBASE}/bin/llvm-config${LLVMVER}
LLVM_BUILD_DEPENDS=	llvm-config${LLVMVER}:devel/llvm${LLVMVER}
LLVM_RUN_DEPENDS=	llc${LLVMVER}:devel/llvm${LLVMVER}

SYNTH_DESC=		Enable Synthesis Features in ghdl
SYNTH_CONFIGURE_ON=	--enable-synth

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libghdl-4_0_0.so

post-install-MCODE-on:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/ghdl \
		${STAGEDIR}${PREFIX}/lib/libghdlvpi.so

post-install-LLVM-on:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/ghdl \
		${STAGEDIR}${PREFIX}/bin/ghwdump \
		${STAGEDIR}${PREFIX}/bin/ghdl1-llvm \
		${STAGEDIR}${PREFIX}/lib/libghdlvpi.so \
		${STAGEDIR}${PREFIX}/lib/libghw.so

do-test:
	@cd ${WRKSRC}/testsuite && \
		${SETENV} ${MAKE_ENV} GHDL=${STAGEDIR}${PREFIX}/bin/ghdl ${SH} testsuite.sh

.include <bsd.port.mk>
