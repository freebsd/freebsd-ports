# $FreeBSD$

PORTNAME=	python-dtrace
PORTVERSION=	0.0.11
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gcj21@cl.cam.ac.uk
COMMENT=	DTrace consumer for Python based on libdtrace

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils cython cython_run

.include <bsd.port.pre.mk>

# TODO: Adjust this check once python-dtrace handles installed dtrace headers
# (https://reviews.freebsd.org/D27884).
MAKE_ENV+=	FREEBSD_SRC_DIR=${SRC_BASE}
.if !exists(${SRC_BASE}/sys/cddl/contrib/opensolaris/uts/common/sys/dtrace.h)
IGNORE=	requires kernel source files in SRC_BASE=${SRC_BASE}
.endif

# Tests not included in the release tarball, uncomment if this changes.
# TEST_DEPENDS=→${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}
#do-test:
#	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -rs -v

.include <bsd.port.post.mk>
