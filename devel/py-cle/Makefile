PORTNAME=	cle
DISTVERSIONPREFIX=	v
DISTVERSION=	${ANGR_VERSION}
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Pythonic interface to analyze binary formats

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}minidump>0:devel/py-minidump@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pefile>0:devel/py-pefile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyelftools>0.25:devel/py-pyelftools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyvex>=${ANGR_VERSION}:security/py-pyvex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sortedcontainers>=2.0:devel/py-sortedcontainers@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR}

USES=		python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	angr
GH_TUPLE=	angr:binaries:${ANGR_BINARIES_TAGNAME}:binaries
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

pre-test:
	@${LN} -Fs ${WRKSRC_binaries} ${WRKDIR}/binaries

do-test:
	@(cd ${WRKSRC} && ${SETENV} ${TEST_ENV} nosetests-${PYTHON_VER} tests/*)

.include "${.CURDIR}/../../security/py-angr/Makefile.version"
.include <bsd.port.mk>
