PORTNAME=	looseversion
PORTVERSION=	1.2.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Python extension for comparing version strings
WWW=		https://pypi.org/project/looseversion/

LICENSE=	PSFL

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}

USES=		cpe python:3.7+
USE_PYTHON=	autoplist concurrent pep517

.include <bsd.port.mk>
