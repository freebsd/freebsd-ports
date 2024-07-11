PORTNAME=	ijson
PORTVERSION=	3.3.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Iterative JSON parser with a standard Python iterator interface
WWW=		https://github.com/ICRAR/ijson

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

OPTIONS_DEFINE=	YAJL
YAJL_DESC=	Enable yajl2_c backend

YAJL_LIB_DEPENDS=	libyajl.so:devel/yajl
YAJL_MAKE_ENV=		IJSON_BUILD_YAJL2C='1'
YAJL_MAKE_ENV_OFF=	IJSON_BUILD_YAJL2C='0'
YAJL_USES=		localbase:ldflags
YAJL_VARS_OFF=		NO_ARCH=yes

post-install-YAJL-on:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
