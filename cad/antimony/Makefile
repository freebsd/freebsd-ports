PORTNAME=	antimony
DISTVERSION=	0.9.3b-37
DISTVERSIONSUFFIX=	-g8b805c67
CATEGORIES=	cad
PKGNAMESUFFIX=	-cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CAD from a parallel universe
WWW=		https://www.mattkeeter.com/projects/antimony/3/

LICENSE=	MIT

BUILD_DEPENDS=	lemon:devel/lemon
LIB_DEPENDS=	${PY_BOOST} \
		libpng16.so:graphics/png

USES=		cmake python qt:5
USE_QT=		concurrent core gui network opengl widgets buildtools:build qmake:build

USE_GITHUB=	yes
GH_ACCOUNT=	mkeeter

CMAKE_ARGS=	-DPython_EXECUTABLE=${PYTHON_CMD}

.include <bsd.port.mk>
