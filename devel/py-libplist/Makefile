PORTREVISION=	1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Python bindings for libplist

LIB_DEPENDS=	libplist-2.0.so:${MASTER_PORT}

USES+=		localbase:ldflags python
USE_PYTHON=	cython3 flavors

CONFIGURE_ENV=	PYTHON_LDFLAGS="`pkg-config --libs python-${PYTHON_VER}`"

BINARY_ALIAS=	cython=cython-${PYTHON_VER}
MASTERDIR=	${.CURDIR:H:H}/devel/libplist
PORTSCOUT=	ignore:1

BUILD_WRKSRC=	${WRKSRC}/cython
INSTALL_WRKSRC=	${BUILD_WRKSRC}

PLIST=		${.CURDIR}/pkg-plist
PLIST_FILES=	include/plist/cython/plist.pxd \
		${PYTHONPREFIX_SITELIBDIR:S|^${PREFIX}/||}/plist.so

SLAVE_PORT=	yes

pre-configure:
	@${REINPLACE_CMD} -e 's|$$(top_builddir)/src/libplist-2.0.la|-lplist-2.0|' \
		${BUILD_WRKSRC}/Makefile.am

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/plist/cython
	${INSTALL_DATA} ${INSTALL_WRKSRC}/plist.pxd \
		${STAGEDIR}${PREFIX}/include/plist/cython

.include "${MASTERDIR}/Makefile"
