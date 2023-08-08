PORTNAME=	nosexcover
PORTVERSION=	1.0.11
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Extends nose cover to add Cobertura-style XML reports
WWW=		https://github.com/cmheisel/nose-xcover

LICENSE=	MIT

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}coverage>=3.4:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
