PORTNAME=	flufl.lock
DISTVERSION=	9.0.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tl:C|[-_.]+|_|g}-${DISTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	NFS-safe file locking with timeouts for POSIX systems
WWW=		https://flufllock.readthedocs.io

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}atpublic>=0:devel/py-atpublic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}diff-cover>=0:devel/py-diff-cover@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sybil>=0:devel/py-sybil@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

NO_ARCH=	yes

# remove the following blocks after setuptools/python.mk update
# incorporating the period (.) portion of name normalisation
# https://packaging.python.org/en/latest/specifications/name-normalization/
# https://packaging.python.org/en/latest/specifications/binary-distribution-format/#escaping-and-unicode
PEP517_INSTALL_CMD=	${PYTHON_CMD} -m installer --destdir ${STAGEDIR} --prefix ${PREFIX} \
		${BUILD_WRKSRC}/dist/${PORTNAME:tl:C|[-_.]+|_|g}-${DISTVERSION}*.whl && \
		${CP} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/flufl_lock-${DISTVERSION}.dist-info/RECORD \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/flufl.lock-${DISTVERSION}.dist-info/RECORD

pre-install:
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/flufl.lock-${DISTVERSION}.dist-info

post-install:
	${RM} -r ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/flufl.lock-${DISTVERSION}.dist-info

.include <bsd.port.mk>
