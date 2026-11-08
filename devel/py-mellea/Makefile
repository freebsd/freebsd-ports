PORTNAME=	mellea
PORTVERSION=	0.8.0
CATEGORIES=	devel python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for writing generative programs
WWW=		https://mellea.ai/ \
		https://github.com/generative-computing/mellea

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-backend>0:devel/py-pdm-backend@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}math-verify>0:math/py-math-verify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mistletoe>=1.4.0:textproc/py-mistletoe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nltk>=3.9:textproc/py-nltk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ollama>=0.5.1:misc/py-ollama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openai>0:misc/py-openai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32.3:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rouge-score>0:textproc/py-rouge-score@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
