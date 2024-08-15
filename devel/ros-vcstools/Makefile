PORTNAME=	ros-vcstools
DISTVERSION=	0.1.42
PORTREVISION=	2
CATEGORIES=	devel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	trueos@norwegianrockcat.com
COMMENT=	Python library for interacting with various VCS systems
WWW=		https://wiki.ros.org/vcstools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-dateutil>=2:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=3:devel/py-pyyaml@${PY_FLAVOR}

USES=	python
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes
GH_ACCOUNT=	vcstools
GH_PROJECT=	vcstools

.include <bsd.port.mk>
