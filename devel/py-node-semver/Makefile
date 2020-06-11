# $FreeBSD$

PORTNAME=	node-semver # PyPI name
DISTVERSION=	0.8.0
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python version of node-semver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	podhmo
GH_PROJECT=	python-semver # PyPI project node-semver points to this project
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
