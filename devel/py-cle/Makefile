PORTNAME=	cle
DISTVERSIONPREFIX=	v
DISTVERSION=	${ANGR_VERSION}
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pythonic interface to analyze binary formats

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}minidump>0:devel/py-minidump@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pefile>0:devel/py-pefile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyelftools>0.25:devel/py-pyelftools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyvex>=${ANGR_VERSION}:security/py-pyvex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sortedcontainers>=2.0:devel/py-sortedcontainers@${PY_FLAVOR}

USES=		angr:binaries,nose python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	angr
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
