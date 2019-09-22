# $FreeBSD$

PORTNAME=	ros-vcstools
DISTVERSION=	0.1.42
CATEGORIES=	devel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	trueos@norwegianrockcat.com
COMMENT=	Python library for interacting with various VCS systems

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=2:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3:devel/py-yaml@${PY_FLAVOR}

USES=	python
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes
GH_ACCOUNT=	vcstools
GH_PROJECT=	vcstools

.include <bsd.port.mk>
