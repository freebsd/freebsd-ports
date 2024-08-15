PORTNAME=	ros-rosinstall_generator
DISTVERSION=	0.1.22
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	trueos@norwegianrockcat.com
COMMENT=	Generator tool for a ROS install distro
WWW=		https://github.com/ros-infrastructure/rosinstall_generator

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argparse>=1:devel/py-argparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=3:devel/py-pyyaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes
GH_ACCOUNT=	ros-infrastructure
GH_PROJECT=	rosinstall_generator
NO_ARCH=	yes

.include <bsd.port.mk>
