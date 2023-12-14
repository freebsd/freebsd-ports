PORTNAME=	pydantic-extra-types
PORTVERSION=	2.2.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pydantic_extra_types-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extra Pydantic types
WWW=		https://docs.pydantic.dev/latest/concepts/types/ \
		https://github.com/pydantic/pydantic-extra-types

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pydantic2>=2.0.3:devel/py-pydantic2@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	ALL
OPTIONS_DEFAULT=ALL
ALL_DESC=	Country codes and phone number support

ALL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}phonenumbers>=8<9:devel/py-phonenumbers@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pycountry>=22<23:textproc/py-pycountry@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}python-ulid>=1:textproc/py-python-ulid@${PY_FLAVOR}

.include <bsd.port.mk>
