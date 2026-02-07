PORTNAME=	monotable
DISTVERSION=	3.2.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	ASCII table with per column format specs and more
WWW=		https://github.com/tmarktaylor/monotable

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

# tests as of 3.2.0: 3 failed, 297 passed in 1.66s (3 failures due tarball not being a git repository)

.include <bsd.port.mk>
