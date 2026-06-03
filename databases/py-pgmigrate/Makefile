PORTNAME=	pgmigrate
DISTVERSION=	1.0.10
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dmitry.wagin@ya.ru
COMMENT=	PostgreSQL migrations made easy
WWW=		https://github.com/yandex/pgmigrate

LICENSE=	PostgreSQL
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>=2.8.2:databases/py-psycopg2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.2:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlparse>=0.3.0:databases/py-sqlparse@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	yandex
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
