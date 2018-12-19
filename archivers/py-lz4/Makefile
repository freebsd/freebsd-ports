# $FreeBSD$

PORTNAME=	lz4
PORTVERSION=	2.1.5
CATEGORIES=	archivers python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python binding for the LZ4 compression library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	liblz4>=1.7.5:archivers/liblz4 \
		${PYTHON_PKGNAMEPREFIX}pkgconfig>=0:devel/py-pkgconfig@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-runner>=0:devel/py-pytest-runner@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR}
LIB_DEPENDS=	liblz4.so:archivers/liblz4
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils py3kplist

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/_version.so \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/block/_block.so \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/frame/_frame.so

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m pytest

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}future>=0:devel/py-future@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
