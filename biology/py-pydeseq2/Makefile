PORTNAME=	pydeseq2
DISTVERSION=	0.5.2
CATEGORIES=	biology python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Python implementation of the popular DESeq2 R package
WWW=		https://github.com/owkin/PyDESeq2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anndata>=0.8.0:devel/py-anndata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}formulaic>=1.0.2:math/py-formulaic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}formulaic_contrasts>=0.2.0:math/py-formulaic-contrasts@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.6.2:math/py-matplotlib@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.4.0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=1.1.0:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>1.11.0:science/py-scipy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
