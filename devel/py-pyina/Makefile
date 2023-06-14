PORTNAME=	pyina
PORTVERSION=	0.2.7
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	MPI parallel map and cluster scheduling
WWW=		https://github.com/uqfoundation/pyina

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=42:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dill>=0.3.6:devel/py-dill@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mpi4py>=1.3:net/py-mpi4py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mystic>=0.4.0:devel/py-mystic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathos>=0.3.0:devel/py-pathos@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pox>=0.3.2:devel/py-pox@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cython pep517

NO_ARCH=	yes

.include <bsd.port.mk>
