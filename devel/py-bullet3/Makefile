PORTNAME=	bullet3
DISTVERSION=	3.25
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python version of 3D collision detection library Bullet
WWW=		https://pybullet.org/wordpress/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}gym>0:math/py-gym@${PY_FLAVOR}

USES=		compiler:c++11-lang gl localbase python
USE_PYTHON=	distutils autoplist
USE_GL=		gl glew

USE_GITHUB=	yes
GH_ACCOUNT=	bulletphysics

CFLAGS_powerpc64=	-mvsx

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pybullet*.so

do-test: # test require graphical environment
	@${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${FILESDIR}/test.py

.include <bsd.port.mk>
