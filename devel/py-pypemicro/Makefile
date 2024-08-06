PORTNAME=	pypemicro
PORTVERSION=	0.1.11
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pypemicro-${PORTVERSION}

MAINTAINER=	aishapoval@mts.ru
COMMENT=	Python PEMicro debug probes support
WWW=		https://pypi.org/project/pypemicro/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python:3.9-3.11
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
