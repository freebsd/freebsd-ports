PORTNAME=	biom-format
PORTVERSION=	2.1.16
CATEGORIES=	biology python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Biological Observation Matrix (BIOM) Format Project
WWW=		https://biom-format.org/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.3.1:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=0.20.0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5py>=2.2.0:science/py-h5py@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cython distutils pytest

.include <bsd.port.pre.mk>

post-extract:
	${RM} -r ${WRKSRC}/tests

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/biom/*.so

.include <bsd.port.post.mk>
