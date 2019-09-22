# $FreeBSD$

PORTNAME=	ros-rosinstall
DISTVERSION=	0.7.8
CATEGORIES=	devel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	trueos@norwegianrockcat.com
COMMENT=	ROS command-line tools for maintaining a workspace from VCS

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ros-vcstools>=0:devel/ros-vcstools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ros-rosdistro>=0:devel/ros-rosdistro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ros-catkin_pkg>=0:devel/ros-catkin_pkg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ros-wstool>=0:devel/ros-wstool@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3:devel/py-yaml@${PY_FLAVOR}

USES=	python
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes
GH_ACCOUNT=	vcstools
GH_PROJECT=	rosinstall

.include <bsd.port.mk>
