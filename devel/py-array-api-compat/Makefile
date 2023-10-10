PORTNAME=	array-api-compat
PORTVERSION=	1.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	array_api_compat-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Array API compatibility library
WWW=		https://data-apis.org/array-api-compat/ \
		https://github.com/data-apis/array-api-compat

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	NUMPY

NUMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR}

.include <bsd.port.mk>
