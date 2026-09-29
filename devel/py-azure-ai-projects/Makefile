PORTNAME=	azure-ai-projects
PORTVERSION=	2.7.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	azure_ai_projects-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Microsoft Corporation Azure AI Projects Client Library for Python
WWW=		https://azure.github.io/azure-sdk-for-python/ \
		https://github.com/Azure/azure-sdk-for-python/tree/main/sdk/ai/azure-ai-projects \
		https://github.com/Azure/azure-sdk-for-python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-core>=1.37.0:devel/py-azure-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-identity>=1.15.0:devel/py-azure-identity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-storage-blob>=12.15.0:devel/py-azure-storage-blob@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isodate>=0.6.1:devel/py-isodate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openai>=3.0.0:misc/py-openai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.11:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	VOICE
VOICE_DESC=	Voice agents

VOICE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.9.0<4.0.0:www/py-aiohttp@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}websockets>=13.0:devel/py-websockets@${PY_FLAVOR}

.include <bsd.port.mk>
