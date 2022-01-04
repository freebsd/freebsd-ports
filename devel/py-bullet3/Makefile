PORTNAME=	bullet3
DISTVERSION=	3.21
CATEGORIES=	devel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python version of 3D collision detection library Bullet

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}gym>0:math/py-gym@${PY_FLAVOR}

USES=		compiler:c++11-lang gl localbase python:3.6+
USE_PYTHON=	distutils autoplist
USE_GL=		gl glew

USE_GITHUB=	yes
GH_ACCOUNT=	bulletphysics

CFLAGS_powerpc64=	-mvsx

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pybullet*.so

do-test: install # test require graphical environment
	@${PYTHON_CMD} ${FILESDIR}/test.py

.include <bsd.port.mk>
