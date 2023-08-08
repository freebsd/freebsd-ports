PORTNAME=	pygltflib
DISTVERSION=	1.15.6
CATEGORIES=	graphics
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for managing 3D objects in Khronos Group gltf, gltf2 formats
WWW=		https://gitlab.com/dodgyville/pygltflib

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dataclasses-json>=0.0.25:devel/py-dataclasses-json@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}deprecated>0:devel/py-deprecated@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils # autoplist is broken

NO_ARCH=	yes

.include <bsd.port.mk>
