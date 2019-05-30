# $FreeBSD$

PORTNAME=	zeep
PORTVERSION=	3.3.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	guiseofreality@gmail.com
COMMENT=	Modern/fast python SOAP client based on lxml / requests

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>=1.4.0:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}attrs>=17.2.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cached-property>=1.3.0:devel/py-cached-property@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defusedxml>=0.4.1:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isodate>=0.5.4:devel/py-isodate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=3.0.0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-toolbelt>=0.7.1:www/py-requests-toolbelt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.7.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flake8>=3.3.0:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}freezegun>=0.3.8:devel/py-freezegun@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isort>=4.2.15:devel/py-isort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock==2.0.0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pretend>=1.0.8:devel/py-pretend@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=2.5.1:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-tornado>=0.4.5:devel/py-pytest-tornado@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=3.1.3:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-mock>=0.7.0:www/py-requests-mock@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

post-patch:
.if ${PYTHON_VER} < 3.5
	${RM} -r ${WRKSRC}/examples/async_client.py ${WRKSRC}/src/zeep/asyncio ${WRKSRC}/tests/test_asyncio_transport.py
.endif

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.post.mk>
