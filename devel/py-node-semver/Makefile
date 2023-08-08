PORTNAME=	node-semver # PyPI name
DISTVERSION=	0.9.0
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python version of node-semver
WWW=		https://github.com/podhmo/python-node-semver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	distutils autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	podhmo
GH_PROJECT=	python-node-semver # PyPI project node-semver points to this project

NO_ARCH=	yes

.include <bsd.port.mk>
