PORTNAME=	setuptools
PORTVERSION=	63.1.0
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python

PATCH_SITES=	https://github.com/pypa/${PORTNAME}/commit/
PATCHFILES=	6653e747c3815b140156249205397ef3719581ee.patch:-p1

# note: before committing a new major version, contact portmgr to
# arrange for an experimental ports run. Untested commits may be
# backed out.
MAINTAINER=	python@FreeBSD.org
COMMENT=	Python packages installer
WWW=		https://github.com/pypa/setuptools \
		https://pypi.org/project/setuptools/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wheel044<0.46.0:devel/py-wheel044@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	allflavors autoplist concurrent pep517 # pytest to return later

CPE_VENDOR=	python

NO_ARCH=	yes

.include <bsd.port.mk>
