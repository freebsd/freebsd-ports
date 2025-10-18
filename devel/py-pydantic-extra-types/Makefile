PORTNAME=	pydantic-extra-types
PORTVERSION=	2.10.6
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
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pydantic2>=2.5.2:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

OPTIONS_DEFINE=	ALL CRON PENDULUM PHONENUMBERS PYCOUNTRY PYTHON_ULID
OPTIONS_DEFAULT=ALL CRON PENDULUM PHONENUMBERS PYCOUNTRY PYTHON_ULID
ALL_DESC=		All optional dependencies
ALL_IMPLIES=		CRON PENDULUM PHONENUMBERS PYCOUNTRY PYTHON_ULID
CRON_DESC=		Cron expression validation
PENDULUM_DESC=		Datetimes support
PHONENUMBERS_DESC=	Phone numbers support
PYCOUNTRY_DESC=		Country codes
PYTHON_ULID_DESC=	ULID support

ALL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymongo>=3.0.0<5.0.0:databases/py-pymongo@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pytz>=2024.1,1:devel/py-pytz@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}semver>=3.0.2:devel/py-semver@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}tzdata>=2024.1:devel/py-tzdata@${PY_FLAVOR}
CRON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cron-converter>=1.2.2:devel/py-cron-converter@${PY_FLAVOR}
PENDULUM_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pendulum>=3.0.0<4.0.0:devel/py-pendulum@${PY_FLAVOR}
PHONENUMBERS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}phonenumbers>=8<10:devel/py-phonenumbers@${PY_FLAVOR}
PYCOUNTRY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycountry>=23:textproc/py-pycountry@${PY_FLAVOR}
PYTHON_ULID_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}python-ulid>=1<4:textproc/py-python-ulid@${PY_FLAVOR}

.include <bsd.port.mk>
