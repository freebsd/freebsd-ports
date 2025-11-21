PORTNAME=	setuptools
PORTVERSION=	80.9.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python


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

.include <bsd.port.pre.mk>

#.if ${PYTHON_REL} < 31000
#EXTRA_PATCHES+=	${PATCHDIR}/py39
#.endif

.include <bsd.port.post.mk>
