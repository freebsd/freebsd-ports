PORTNAME=	pygls
PORTVERSION=	2.1.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pythonic generic language server (pronounced like 'pie glass')
WWW=		https://pygls.readthedocs.io/en/latest/ \
		https://github.com/openlawlibrary/pygls

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=24.3.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cattrs>=23.1.2:devel/py-cattrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lsprotocol>=2025.0.0<2025.0.0_99:devel/py-lsprotocol@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	WS
WS_DESC=	WebSocket support

WS_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}websockets>=13.0:devel/py-websockets@${PY_FLAVOR}

.include <bsd.port.mk>
