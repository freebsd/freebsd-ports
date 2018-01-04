# $FreeBSD$

PORTNAME=	bullet3
DISTVERSION=	2.87
CATEGORIES=	devel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python version of 3D collision detection library Bullet

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		compiler:c++11-lang localbase python
USE_GITHUB=	yes
GH_ACCOUNT=	bulletphysics
USE_PYTHON=	autoplist distutils
USE_GL=		gl glew

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pybullet.so

.include <bsd.port.mk>
