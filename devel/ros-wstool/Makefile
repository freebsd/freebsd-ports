PORTNAME=	ros-wstool
DISTVERSION=	0.1.18
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	trueos@norwegianrockcat.com
COMMENT=	Tool for managing a workspace of heterogenous SCM repositories
WWW=		https://github.com/vcstools/wstool

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ros-vcstools>=0:devel/ros-vcstools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=3:devel/py-pyyaml@${PY_FLAVOR}

USES=	python
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes
GH_ACCOUNT=	vcstools
GH_PROJECT=	wstool

.include <bsd.port.mk>
