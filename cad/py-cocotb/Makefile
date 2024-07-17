PORTNAME=	cocotb
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.0
CATEGORIES=	cad python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Coroutine based cosimulation library for writing VHDL and Verilog
WWW=		https://www.cocotb.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}find-libpython>0:devel/py-find-libpython@${PY_FLAVOR} \
		gtkwave:cad/gtkwave
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=3.10.0:devel/py-pytest-mock@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	pep517 autoplist
USE_GITHUB=	yes

SHEBANG_GLOB=	*.py

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		PATH=${STAGEDIR}${LOCALBASE}/bin:${PATH} \
		LD_LIBRARY_PATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/cocotb/libs \
		SIM=icarus

OPTIONS_DEFINE=		IVERILOG VERILATOR # GHDL - TODO
OPTIONS_DEFAULT=	IVERILOG VERILATOR

IVERILOG_DESC=		Iverilog dependency
IVERILOG_RUN_DEPENDS=	iverilog:cad/iverilog

VERILATOR_DESC=		Verilator dependency
VERILATOR_RUN_DEPENDS=	verilator:cad/verilator

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/cocotb/simulator${PYTHON_EXT_SUFFIX}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/cocotb/libs/lib*.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/cocotb/libs/libcocotbvpi_icarus.vpl

do-test: # some tests fail, see https://github.com/cocotb/cocotb/issues/3236, https://github.com/cocotb/cocotb/issues/3435
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${GMAKE} test

.include <bsd.port.mk>
