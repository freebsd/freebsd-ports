# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	pyina
PORTVERSION=	0.2.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	MPI parallel map and cluster scheduling

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dill>=0.3.4:devel/py-dill@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mpi4py>=1.3:net/py-mpi4py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathos>=0.2.8:devel/py-pathos@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pox>=0.3.0:devel/py-pox@${PY_FLAVOR}

USES=		python:3.7+ zip
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
