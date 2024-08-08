PORTNAME=	ollama
DISTVERSION=	0.3.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Ollama Python library
WWW=		https://github.com/ollama/ollama-python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.9.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=4.3.0:devel/py-anyio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=2024.2.2:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}exceptiongroup>=1.2.0:devel/py-exceptiongroup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h11>=0.14.0:net/py-h11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpcore>=1.0.4:www/py-httpcore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.27.0:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>=3.6:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sniffio>=1.3.1:devel/py-sniffio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.10.0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

.include <bsd.port.mk>
