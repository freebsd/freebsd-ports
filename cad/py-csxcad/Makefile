PORTNAME=	csxcad
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.3
CATEGORIES=	cad
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library to describe geometrical objects
WWW=		https://github.com/thliebig/CSXCAD

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

LIB_DEPENDS=	libCSXCAD.so:cad/csxcad

USES=		python
USE_PYTHON=	distutils cython autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	thliebig
GH_PROJECT=	${PORTNAME:tu}

CFLAGS+=	-I${WRKSRC}

WRKSRC_SUBDIR=	python

post-patch:
	@${CP} ${WRKSRC}/../src/*.h ${WRKSRC}/CSXCAD 

post-install:
.for name in CSPrimitives CSProperties CSRectGrid CSTransform CSXCAD ParameterObjects Utilities
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/CSXCAD/${name}${PYTHON_EXT_SUFFIX}.so
.endfor

.include <bsd.port.mk>
