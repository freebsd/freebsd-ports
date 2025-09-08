PORTNAME=	greenlet
PORTVERSION=	3.2.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Light-weight microthreads for Python
WWW=		https://greenlet.readthedocs.io/en/latest/ \
		https://github.com/python-greenlet/greenlet

LICENSE=	MIT PSFL
LICENSE_COMB=	dual
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE
LICENSE_FILE_PSFL=	${WRKSRC}/LICENSE.PSF

NOT_FOR_ARCHS=	mips mips64
NOT_FOR_ARCHS_REASON=	greenlet needs to be ported to this platform

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=40.8.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
