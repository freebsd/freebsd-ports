PORTNAME=	jsonnet
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.0
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	timp87@gmail.com
COMMENT=	Python bindings for Jsonnet - The data templating language

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjsonnet.so:devel/jsonnet

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}

USES=		compiler:c++11-lang python:3.6+ localbase

USE_GITHUB=	yes
GH_ACCOUNT=	google

USE_PYTHON=	distutils autoplist

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_jsonnet${PYTHON_EXT_SUFFIX}.so

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs

.include	<bsd.port.mk>
