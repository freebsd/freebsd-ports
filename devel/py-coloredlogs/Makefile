PORTNAME=	coloredlogs
PORTVERSION=	15.0.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Colored terminal output for Python logging module
WWW=		https://coloredlogs.readthedocs.io/en/latest/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}humanfriendly>=9.1:textproc/py-humanfriendly@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	CRON
CRON_DESC=	Cron support

CRON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}capturer>=2.4:devel/py-capturer@${PY_FLAVOR}

.include <bsd.port.mk>
