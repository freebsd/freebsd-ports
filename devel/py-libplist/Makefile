# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python bindings for libplist

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-03-19

LIB_DEPENDS=	libplist.so:${MASTER_PORT}

PORTSCOUT=	ignore:1

USES=		python:2.7
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
	@${REINPLACE_CMD} -e 's,../src/libplist.la,-lplist,' \
		-e 's,$$(plist_la_DEPENDENCIES),,' \
		${BUILD_WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/plist/cython
	${INSTALL_DATA} ${INSTALL_WRKSRC}/plist.pxd \
		${STAGEDIR}${PREFIX}/include/plist/cython

.include "${MASTERDIR}/Makefile"
