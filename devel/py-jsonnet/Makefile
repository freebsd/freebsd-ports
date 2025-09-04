PORTNAME=	jsonnet
DISTVERSIONPREFIX=	v
DISTVERSION=	0.21.0
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	timp87@gmail.com
COMMENT=	Python bindings for Jsonnet - The data templating language
WWW=		https://github.com/google/jsonnet

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjsonnet.so:devel/jsonnet

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}

USES=		compiler:c++17-lang localbase python

USE_GITHUB=	yes
GH_ACCOUNT=	google

USE_PYTHON=	autoplist distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_jsonnet${PYTHON_TAG}.so

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs

.include <bsd.port.mk>
