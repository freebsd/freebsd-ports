PORTNAME=	tagpy
PORTVERSION=	2022.1
PORTREVISION=	0
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python bindings for Scott Wheeler's TagLib
WWW=		https://mathema.tician.de/software/tagpy

LICENSE=	MIT

BROKEN=		does not build with audio/taglib 2.x
EXPIRATION_DATE=2024-08-31

LIB_DEPENDS=	${PY_BOOST} \
		libtag.so:audio/taglib

USES=		compiler:c++11-lang python shebangfix
USE_PYTHON=	autoplist distutils

PYDISTUTILS_BUILD_TARGET=	build_ext
PYDISTUTILS_BUILDARGS=	--include-dirs="${LOCALBASE}/include/taglib" \
			--include-dirs="${LOCALBASE}/include" \
			--library-dirs="${LOCALBASE}/lib"

CPPFLAGS+=	-D_LIBCPP_ENABLE_CXX17_REMOVED_AUTO_PTR

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_tagpy.cpython-${PYTHON_SUFFIX}.so

.include <bsd.port.mk>
