PORTNAME=	PyOpenGL
PORTVERSION=	3.1.5
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-accelerate
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	OpenGL acceleration code for PyOpenGL
WWW=		http://pyopengl.sourceforge.net/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}

USE_PYTHON=	autoplist distutils cython
USES=		python:3.6+

.include <bsd.port.mk>
