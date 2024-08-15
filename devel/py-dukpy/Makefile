PORTNAME=	dukpy
PORTVERSION=	0.4.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple JavaScript interpreter for Python
WWW=		https://github.com/amol-/dukpy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mutf8>=0:devel/py-mutf8@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

OPTIONS_DEFINE=	WEBASSETS
OPTIONS_DEFAULT=WEBASSETS
WEBASSETS_DESC=	Asset management

WEBASSETS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}webassets>=0:www/py-webassets@${PY_FLAVOR}

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
