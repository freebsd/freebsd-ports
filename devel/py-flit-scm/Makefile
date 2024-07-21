PORTNAME=	flit-scm
PORTVERSION=	1.7.0
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	flit_scm-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PEP 518 build backend that uses setuptools_scm to generate a version file
WWW=		https://gitlab.com/WillDaSilva/flit_scm

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.5<4:devel/py-flit-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.4:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PY_TOMLI}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.5<4:devel/py-flit-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.4:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PY_TOMLI}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
