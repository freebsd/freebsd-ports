PORTNAME=	pydantic-extra-types
PORTVERSION=	2.9.0
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
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pydantic2>=2.5.2:devel/py-pydantic2@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

OPTIONS_DEFINE=	ALL PENDULUM PHONENUMBERS PYCOUNTRY PYTHON_ULID
OPTIONS_DEFAULT=ALL PENDULUM PHONENUMBERS PYCOUNTRY PYTHON_ULID
ALL_DESC=	All external supports
PENDULUM_DESC=	Datetimes support
PHONENUMBERS_DESC=	Phone numbers support
PYCOUNTRY_DESC=	Country codes
PYTHON_ULID_DESC=	ULID support

ALL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pendulum>=2.0.0<4.0.0:devel/py-pendulum@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}phonenumbers>=8<9:devel/py-phonenumbers@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pycountry>=23:textproc/py-pycountry@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}python-ulid>=1<3:textproc/py-python-ulid@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pytz>=2024.1,1:devel/py-pytz@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}semver>=3.0.2:devel/py-semver@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}tzdata>=2024.1:devel/py-tzdata@${PY_FLAVOR}
PENDULUM_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pendulum>=2.0.0<4.0.0:devel/py-pendulum@${PY_FLAVOR}
PHONENUMBERS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}phonenumbers>=8<9:devel/py-phonenumbers@${PY_FLAVOR}
PYCOUNTRY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycountry>=23:textproc/py-pycountry@${PY_FLAVOR}
PYTHON_ULID_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}python-ulid>=1<3:textproc/py-python-ulid@${PY_FLAVOR}

.include <bsd.port.mk>
