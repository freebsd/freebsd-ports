PORTNAME=	pylint-venv
DISTVERSION=	2.3.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pylint-venv allows use same Pylint with different virtual environments
WWW=		https://github.com/jgosmann/pylint-venv/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

POST_PLIST+=		fix-plist

# upstream stopped providing setup.py
post-patch:
	@${ECHO_CMD} 'import setuptools; setuptools.setup()' > ${WRKSRC}/setup.py

post-install:
	@cd ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} && \
		${REINPLACE_CMD} \
			-e 's|^Version:.*|Version: ${DISTVERSION}|' \
			pylint_venv-0.0.0-py${PYTHON_VER}.egg-info/PKG-INFO && \
		${MV} pylint_venv-0.0.0-py${PYTHON_VER}.egg-info pylint_venv-${DISTVERSION}-py${PYTHON_VER}.egg-info

fix-plist:
	${REINPLACE_CMD} -e 's|0\.0\.0|${DISTVERSION}|' ${TMPPLIST}

.include <bsd.port.mk>
