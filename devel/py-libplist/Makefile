PORTREVISION=	0
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Python bindings for libplist

LIB_DEPENDS=	libplist-2.0.so:${MASTER_PORT}

PORTSCOUT=	ignore:1

USES=		python:3.6+
USE_PYTHON=	flavors cython
BINARY_ALIAS=	cython=cython-${PYTHON_VER}
CONFIGURE_ENV=	PYTHON_LDFLAGS="`pkg-config --libs python-${PYTHON_VER}`"
SLAVE_PORT=	yes
MASTERDIR=	${.CURDIR:H:H}/devel/libplist
# Required to reference installed libplist.
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST=		${.CURDIR}/pkg-plist

BUILD_WRKSRC=	${WRKSRC}/cython
INSTALL_WRKSRC=	${BUILD_WRKSRC}

PLIST_FILES=	include/plist/cython/plist.pxd \
		${PYTHONPREFIX_SITELIBDIR:S,^${PREFIX}/,,}/plist.a \
		${PYTHONPREFIX_SITELIBDIR:S,^${PREFIX}/,,}/plist.so

pre-configure:
	@${REINPLACE_CMD} -e 's|$$(top_builddir)/src/libplist-2.0.la|-lplist-2.0|' \
		${BUILD_WRKSRC}/Makefile.am

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/plist/cython
	${INSTALL_DATA} ${INSTALL_WRKSRC}/plist.pxd \
		${STAGEDIR}${PREFIX}/include/plist/cython

.include "${MASTERDIR}/Makefile"
