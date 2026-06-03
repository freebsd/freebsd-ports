PORTNAME=	deepTools
DISTVERSION=	3.5.6
CATEGORIES=	biology python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	deeptools-${DISTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	User-friendly tools for exploring deep-sequencing data
WWW=		https://github.com/deeptools/deepTools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.17.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.5.0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysam>=0.14.0:biology/py-pysam@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}py2bit>=0.2.0:biology/py-py2bit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpydoc>=0.5:textproc/py-numpydoc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyBigWig>=0.2.1:biology/py-pybigwig@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plotly>=4.9:graphics/py-plotly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}deeptoolsintervals>=0.1.8:biology/py-deeptoolsintervals@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
