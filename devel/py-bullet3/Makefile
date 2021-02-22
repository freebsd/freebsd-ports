# $FreeBSD$

PORTNAME=	bullet3
DISTVERSION=	3.08
PORTREVISION=	2
CATEGORIES=	devel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python version of 3D collision detection library Bullet

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		compiler:c++11-lang gl localbase python:3.6+
USE_PYTHON=	autoplist distutils
USE_GL=		gl glew

USE_GITHUB=	yes
GH_ACCOUNT=	bulletphysics

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pybullet*.so

.include <bsd.port.mk>
