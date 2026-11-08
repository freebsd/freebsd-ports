PORTNAME=	xopen
DISTVERSION=	2.1.0
CATEGORIES=	archivers python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Open compressed files transparently
WWW=		https://pypi.org/project/xopen/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	pigz>=0:archivers/pigz
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cython pep517

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31400
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}backports.zstd>0:devel/py-backports.zstd@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
