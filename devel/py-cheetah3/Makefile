PORTNAME=	cheetah
DISTVERSION=	3.4.0.post5
CATEGORIES=	devel textproc www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	3

MAINTAINER=	FreeBSD@ShaneWare.Biz
COMMENT=	HTML template engine for Python
WWW=		https://cheetahtemplate.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown>=2.0.3:textproc/py-markdown@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR}

USES=		python

USE_GITHUB=	yes
GH_ACCOUNT=	CheetahTemplate3
GH_PROJECT=	cheetah3
USE_PYTHON=	autoplist concurrent pep517 pytest

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/Cheetah/*.so

do-test:
	@cd ${WRKSRC}/Cheetah/Tests && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} Test.py

.include <bsd.port.mk>
