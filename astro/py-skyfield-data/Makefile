PORTNAME=	skyfield_data
PORTVERSION=	7.0.0
CATEGORIES=	astro python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Minimal data files to work with py-skyfield
WWW=		https://github.com/brunobord/skyfield-data

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}skyfield>0:astro/py-skyfield@${PY_FLAVOR}
TEST_DEPENDS=	py.test:devel/py-pytest@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}pytest-mypy>0:devel/py-pytest-mypy@${PY_FLAVOR}

#USE_GITHUB=	yes
#GH_ACCOUNT=	brunobord

USES=		python
USE_PYTHON=	distutils

NO_ARCH=	yes

do-test: install
	(cd ${WRKSRC} && py.test)

.include <bsd.port.mk>
