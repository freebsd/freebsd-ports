PORTNAME=	ros-catkin_pkg
DISTVERSION=	0.4.14
CATEGORIES=	devel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	trueos@norwegianrockcat.com
COMMENT=	Standard Python library for the catkin build system

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argparse>=1:devel/py-argparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=2:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0:textproc/py-docutils@${PY_FLAVOR}

USES=		python:3.6+

USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	ros-infrastructure
GH_PROJECT=	catkin_pkg
NO_ARCH=	yes

.include <bsd.port.mk>
