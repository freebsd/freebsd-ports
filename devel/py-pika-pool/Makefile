PORTNAME=	pika-pool
PORTVERSION=	0.1.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pika connection pooling
WWW=		https://github.com/bninja/pika-pool

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pika>=0.9.0:devel/py-pika@${PY_FLAVOR}

NO_ARCH=	yes

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
