PORTNAME=	cocotb
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.2
CATEGORIES=	cad python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Coroutine based cosimulation library for writing VHDL and Verilog
WWW=		https://www.cocotb.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}find-libpython>0:devel/py-find-libpython@${PY_FLAVOR} \
		gtkwave:cad/gtkwave

USES=		python:3.6+
USE_PYTHON=	pep517 autoplist pytest # https://github.com/cocotb/cocotb/issues/3230
USE_GITHUB=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

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

.include <bsd.port.mk>
