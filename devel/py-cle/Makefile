# $FreeBSD$

PORTNAME=	cle
DISTVERSION=	8.20.1.7
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Pythonic interface to analyze binary formats

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}minidump>0:devel/py-minidump@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pefile>0:devel/py-pefile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyelftools>0:devel/py-pyelftools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyvex>=${DISTVERSION}:security/py-pyvex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sortedcontainers>=2.0:devel/py-sortedcontainers@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR}

USES=		python:3.6+
USE_GITHUB=	nodefault
GH_TUPLE=	angr:${PORTNAME}:18f073190e37310737ee2d79ba52f72a481b4a9f:tests \
		angr:binaries:f2de6d7a0474d22130ffadd042327536a6fda114:binaries
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

pre-test:
	@${LN} -Fs ${WRKSRC_tests}/tests ${WRKSRC}/tests
	@${LN} -Fs ${WRKSRC_binaries} ${WRKDIR}/binaries

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} nosetests-${PYTHON_VER} tests/*)

.include <bsd.port.mk>
