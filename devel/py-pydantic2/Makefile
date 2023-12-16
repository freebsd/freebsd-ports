PORTNAME=	pydantic
PORTVERSION=	2.5.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Data validation using Python type hints
WWW=		https://docs.pydantic.dev/latest/ \
		https://github.com/pydantic/pydantic

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-fancy-pypi-readme>=22.5.0:devel/py-hatch-fancy-pypi-readme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}annotated-types>=0.4.0:devel/py-annotated-types@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-core>=2.14.5<2.14.5_99:devel/py-pydantic-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.6.1:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
