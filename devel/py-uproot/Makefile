PORTNAME=	uproot
PORTVERSION=	5.6.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	ROOT I/O in pure Python and NumPy
WWW=		https://uproot.readthedocs.io/en/latest/ \
		https://github.com/scikit-hep/uproot5

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}awkward>=2.4.6:math/py-awkward@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cramjam>=2.5.0:archivers/py-cramjam@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fsspec>=0:filesystems/py-fsspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xxhash>=0:devel/py-xxhash@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	HTTP S3 XROOTD
HTTP_DESC=	Access remote files via HTTP/HTTPS
S3_DESC=	Access Amazon S3 storage
XROOTD_DESC=	Access extended ROOT daemon

HTTP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=0:www/py-aiohttp@${PY_FLAVOR}
S3_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}s3fs>=0:filesystems/py-s3fs@${PY_FLAVOR}
XROOTD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fsspec-xrootd>=0.5.0:filesystems/py-fsspec-xrootd@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.1.0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
