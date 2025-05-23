PORTNAME=	oslex
DISTVERSION=	0.1.3
CATEGORIES=	devel misc
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dch@FreeBSD.org
COMMENT=	OS-independent wrapper for shlex
WWW=		https://github.com/petamas/oslex

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# BUILD_DEPENDS=	${PY_SETUPTOOLS} \
# 		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
