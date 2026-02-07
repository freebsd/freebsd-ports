PORTNAME=	preshed
PORTVERSION=	3.0.12
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/explosion/preshed/releases/download/release-v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	3

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Cython hash table that trusts the keys are pre-hashed
WWW=		https://github.com/explosion/preshed

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cymem>=2.0.2<2.1.0:devel/py-cymem@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}murmurhash>=0.28.0<1.1.0:devel/py-murmurhash@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cymem>=2.0.2<2.1.0:devel/py-cymem@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}murmurhash>=0.28.0<1.1.0:devel/py-murmurhash@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cython pep517 pytest

TEST_WRKSRC=	${STAGEDIR}${PYTHON_SITELIBDIR}

PORTSCOUT=	limit^3\.

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
