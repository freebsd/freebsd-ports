PORTNAME=	traitlets
DISTVERSION=	5.8.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Configuration system for Python applications
WWW=		https://github.com/ipython/traitlets

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipython_genutils>0:devel/py-ipython_genutils@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	distutils autoplist pytest

NO_ARCH=	yes

# upstream stopped providing setup.py
post-patch:
	@${ECHO_CMD} 'import setuptools; setuptools.setup()' > ${WRKSRC}/setup.py

post-install:
	@${REINPLACE_CMD} -i '' -e 's|Version: .*|Version: ${DISTVERSION}|' ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/traitlets-*/PKG-INFO

.include <bsd.port.mk>
