PORTNAME=	mime
PORTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gettoknowmi@yahoo.com
COMMENT=	MIME types are used in MIME-compliant communications
WWW=		https://github.com/liluo/mime

LICENSE=	MIT
LICENSE_FILE=	${FILESDIR}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR}

USES=		python:run
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

#Error: Python package installs top-level 'tests/' directory in site-packages
#	Error:   Location: lib/python3.12/site-packages/tests
#	Error: This causes file conflicts with other packages. Exclude it via pyproject.toml:
#Error:   [tool.setuptools.packages.find]
#	Error:   exclude = ["tests", "tests.*"]
.if ${PYTHON_REL} >= 31200
IGNORE=		Does not support Python 3.12 or later
.endif

.include <bsd.port.post.mk>
