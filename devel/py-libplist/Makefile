# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Python bindings for libplist

LIB_DEPENDS=	libplist.so:${MASTER_PORT}
BUILD_DEPENDS=	cython:lang/cython

USES=		python
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
	@${REINPLACE_CMD} -e 's,../src/libplist.la,-lplist,' \
		-e 's,$$(plist_la_DEPENDENCIES),,' \
		${BUILD_WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/plist/cython
	${INSTALL_DATA} ${INSTALL_WRKSRC}/plist.pxd \
		${STAGEDIR}${PREFIX}/include/plist/cython

.include "${MASTERDIR}/Makefile"
