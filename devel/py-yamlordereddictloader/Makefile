PORTNAME=	yamlordereddictloader
DISTVERSION=	0.4.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sergey@akhmatov.ru
COMMENT=	Loader and a dumper for PyYAML allowing to keep items order
WWW=		https://pypi.python.org/pypi/yamlordereddictloader

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Deprecated by upstream and no longer actively maintained, please use devel/py-yamlloader instead
EXPIRATION_DATE=2026-06-30

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=5.1:devel/py-pyyaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
