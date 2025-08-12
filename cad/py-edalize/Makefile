PORTNAME=	edalize
DISTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	cad python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for interfacing EDA tools
WWW=		https://github.com/olofk/edalize

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=3:devel/py-Jinja2@${PY_FLAVOR} \
		gmake:devel/gmake \
		yosys:cad/yosys
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}vunit-hdl>0:cad/py-vunit-hdl@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	pep517 autoplist pytest

SHEBANG_FILES=	tests/mock_commands/* scripts/el_docker

NO_ARCH=	yes

post-patch:
	@${GREP} -rl '"make"' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -i '' -e 's|"make"|"${GMAKE}"|'
	@${GREP} -rl '"python3"' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -i '' -e 's|"python3"|"${PYTHON_CMD}"|'
	@${GREP} -rl 'shell python3 ' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -i '' -e 's|shell python3 |shell ${PYTHON_CMD} |'
	@${GREP} -rl '$$(shell which python3)' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -i '' -e 's|$$(shell which python3)|${PYTHON_CMD}|'
	@${REINPLACE_CMD} -i '' -e 's|/usr/bin/env python3|${PYTHON_CMD}|' ${WRKSRC}/tests/mock_commands/vcs

# testsuite has intermittent failures: in many runs many tests fail, but sometimes all tests but 1 succeed, see https://github.com/olofk/edalize/issues/368
# 2 tests (test_modelsim,test_modelsim_common_compilation) always fail because it depends on Intel's modelsim

.include <bsd.port.mk>
