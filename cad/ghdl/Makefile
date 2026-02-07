PORTNAME=	ghdl
DISTVERSIONPREFIX=	v
DISTVERSION=	5.1.1
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	GNU VHDL simulator
WWW=		https://github.com/ghdl/ghdl

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.md

BROKEN_aarch64=	build breaks, see https://github.com/ghdl/ghdl/issues/2639

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyTooling>=2.11.0:devel/py-pyTooling@${PY_FLAVOR} \
		bash:shells/bash

USES=		ada:run gmake python:test shebangfix
USE_GITHUB=	yes
USE_LDCONFIG=	yes

SHEBANG_FILES=	testsuite/testsuite.sh

GNU_CONFIGURE=	yes

NO_SHLIB_REQUIRES_GLOB=	libgnat-12.so
PIE_UNSAFE=	yes

OPTIONS_DEFINE=		SYNTH
OPTIONS_DEFAULT=	LLVM SYNTH
OPTIONS_SINGLE=		BACKEND
OPTIONS_SINGLE_BACKEND=	LLVM MCODE
OPTIONS_SUB=		yes

LLVM_DESC=	Use the LLVM backend
MCODE_DESC=	Use the MCODE backend
# MCODE is enabled by default and doesn't require any configuration options
SYNTH_DESC=	Enable Synthesis Features in ghdl

LLVM_USES=		llvm:lib ncurses
LLVM_CONFIGURE_ON=	--with-llvm-config=${LOCALBASE}/bin/llvm-config${LLVM_VERSION}
SYNTH_CONFIGURE_ON=	--enable-synth

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libghdl-${DISTVERSION:S/./_/g}.so

post-install-LLVM-on:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/ghdl \
		${STAGEDIR}${PREFIX}/bin/ghwdump \
		${STAGEDIR}${PREFIX}/bin/ghdl1-llvm \
		${STAGEDIR}${PREFIX}/lib/libghdlvpi.so \
		${STAGEDIR}${PREFIX}/lib/libghw.so

post-install-MCODE-on:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/ghdl \
		${STAGEDIR}${PREFIX}/lib/libghdlvpi.so

do-test:
	@cd ${WRKSRC}/testsuite && \
		${SETENV} ${MAKE_ENV} GHDL=${STAGEDIR}${PREFIX}/bin/ghdl ${SH} testsuite.sh

.include <bsd.port.mk>
