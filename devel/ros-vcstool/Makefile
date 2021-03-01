# $FreeBSD$

PORTNAME=	ros-vcstool
DISTVERSION=	0.2.15
CATEGORIES=	devel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	trueos@norwegianrockcat.com
COMMENT=	Version control system (VCS) tool for ROS

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=3:devel/py-yaml@${PY_FLAVOR}

USES=	python:3.6+

USE_GITHUB=	yes
GH_ACCOUNT=	dirk-thomas
GH_PROJECT=	vcstool

USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
