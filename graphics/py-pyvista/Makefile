PORTNAME=	pyvista
DISTVERSION=	0.34.2
PORTREVISION=	6
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pythonic interface to VTK
WWW=		https://github.com/pyvista/pyvista

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}appdirs>0:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}imageio>0:graphics/py-imageio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scooby>=0.5.1:devel/py-scooby@${PY_FLAVOR} \
		vtk${VTK_VER:R}>0:math/vtk${VTK_VER:R}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <../../math/vtk9/Makefile.version>
.include <bsd.port.mk>
