PORTNAME=	greenlet
PORTVERSION=	3.0.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Light-weight microthreads for Python
WWW=		https://github.com/python-greenlet/greenlet

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=		mips mips64
NOT_FOR_ARCHS_REASON=	greenlet needs to be ported to this platform

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=40.8.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

CPPFLAGS+=	-Dregister=

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
