PORTNAME=	ros-vcstool
DISTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	trueos@norwegianrockcat.com
COMMENT=	Version control system (VCS) tool for ROS
WWW=		https://wiki.ros.org/vcstool

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=3:devel/py-pyyaml@${PY_FLAVOR}

USES=		python

USE_GITHUB=	yes
GH_ACCOUNT=	dirk-thomas
GH_PROJECT=	vcstool

USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
