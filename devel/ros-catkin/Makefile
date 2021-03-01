# $FreeBSD$

PORTNAME=	ros-catkin
DISTVERSION=	0.8.9
CATEGORIES=	devel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	trueos@norwegianrockcat.com
COMMENT=	CMake-based build system that is used to build all packages in ROS

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake>=3.15:devel/cmake \
		googletest>=1.8.1:devel/googletest \
		${PYTHON_PKGNAMEPREFIX}ros-catkin_pkg>=0.4.0:devel/ros-catkin_pkg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}empy>=1:textproc/py-empy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${PY_FLAVOR}

USES=		python:3.6+

USE_PYTHON=	autoplist distutils

USE_GITHUB=	yes
GH_ACCOUNT=	ros
GH_PROJECT=	catkin

.include <bsd.port.mk>
