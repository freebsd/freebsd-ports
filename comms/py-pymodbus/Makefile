PORTNAME=	pymodbus
DISTVERSION=	3.3.0
CATEGORIES=	comms python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	chris@chrullrich.net
COMMENT=	Implementation of the Modbus protocol
WWW=		https://github.com/pymodbus-dev/pymodbus/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.8+
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=	REPL SERIAL DATASTORE_REDIS DATASTORE_SQL
OPTIONS_DEFAULT=REPL
REPL_DESC=	Interactive REPL console
SERIAL_DESC=	Support serial port
DATASTORE_REDIS_DESC=	Use Redis for server data
DATASTORE_SQL_DESC=	Use database for server data (via SQLAlchemy)

REPL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.8.1:www/py-aiohttp@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}prompt-toolkit>=3.0.8:devel/py-prompt-toolkit@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}typer>=0.6.1:devel/py-typer@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR}
REPL_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-NO_REPL

SERIAL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyserial>=3.5:comms/py-pyserial@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyserial-asyncio>=0.6:comms/py-pyserial-asyncio@${PY_FLAVOR}

DATASTORE_REDIS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis>0:databases/py-redis@${PY_FLAVOR}
DATASTORE_SQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy14>0:databases/py-sqlalchemy14@${PY_FLAVOR}

NO_ARCH=	yes

.include <bsd.port.mk>
