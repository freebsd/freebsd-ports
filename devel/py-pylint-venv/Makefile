PORTNAME=	pylint-venv
PORTVERSION=	2.3.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pylint-venv allows use same Pylint with different virtual environments
WWW=		https://github.com/jgosmann/pylint-venv/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

# upstream stopped providing setup.py
post-patch:
	@${ECHO_CMD} 'import setuptools; setuptools.setup()' > ${WRKSRC}/setup.py

.include <bsd.port.mk>
