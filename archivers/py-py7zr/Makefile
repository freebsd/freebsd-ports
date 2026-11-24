PORTNAME=	py7zr
DISTVERSION=	1.1.4
PORTREVISION=	1
CATEGORIES=	archivers python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@wener.org
COMMENT=	Pure Python 7-zip library
WWW=		https://py7zr.readthedocs.io/ \
		https://github.com/miurahr/py7zr

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}brotli>=0:archivers/py-brotli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}inflate64>=0:archivers/py-inflate64@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}multivolumefile>=0:archivers/py-multivolumefile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybcj>=0:archivers/py-pybcj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodomex>=0:security/py-pycryptodomex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyppmd>=0:archivers/py-pyppmd@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}texttable>=0:textproc/py-texttable@${PY_FLAVOR}

USES=		cpe python
CPE_VENDOR=	py7zr_project
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31400
RUN_DEPENDS+=	${PY_BACKPORTS.ZSTD}
.endif

.include <bsd.port.post.mk>
