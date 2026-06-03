PORTNAME=	pynvml
PORTVERSION=	13.0.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python Bindings for the NVIDIA Management Library
WWW=		https://github.com/gpuopenanalytics/pynvml

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nvidia_ml_py>=12.0.0:devel/py-nvidia-ml-py@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -c 'import pynvml_utils; assert pynvml_utils.__version__ == "${PORTVERSION}"; assert "Provides a Python interface" in pynvml_utils.nvidia_smi.DeviceQuery("--help"); assert "Provides a Python interface" in pynvml_utils.nvidia_smi.XmlDeviceQuery("--help")'

.include <bsd.port.mk>
