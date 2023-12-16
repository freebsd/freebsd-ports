PORTNAME=	noseofyeti
DISTVERSIONPREFIX=release-
DISTVERSION=	2.4.3
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Python codec that provides an RSpec style DSL for Python
WWW=		https://github.com/delfick/nose-of-yeti

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-helpers-namespace>0:devel/py-pytest-helpers-namespace@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist concurrent pep517

GH_ACCOUNT=	delfick
GH_PROJECT=	nose-of-yeti

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs -o addopts= \
	-k 'not test_registering_codec_doesnt_lead_to_error'

.include <bsd.port.mk>
