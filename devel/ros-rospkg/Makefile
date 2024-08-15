PORTNAME=	ros-rospkg
DISTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	trueos@norwegianrockcat.com
COMMENT=	Python library for ROS packaging system
WWW=		https://wiki.ros.org/rospkg

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argparse>=1:devel/py-argparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=3:devel/py-pyyaml@${PY_FLAVOR}

USES=	python
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes
GH_ACCOUNT=	ros-infrastructure
GH_PROJECT=	rospkg

.include <bsd.port.mk>
