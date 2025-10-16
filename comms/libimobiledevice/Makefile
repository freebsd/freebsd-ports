PORTNAME=	libimobiledevice
DISTVERSION=	1.4.0
PORTREVISION?=	0
CATEGORIES?=	comms
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER?=	jhale@FreeBSD.org
COMMENT?=	Library to communicate with Apple iOS devices
WWW=		https://www.libimobiledevice.org

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libplist-2.0.so:devel/libplist

USES=		cpe libtool localbase:ldflags pkgconfig \
		readline ssl tar:bz2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= openssl_CFLAGS="-I${OPENSSLINC}" \
		openssl_LIBS="-L${OPENSSLLIB} -lssl -lcrypto"
INSTALL_TARGET=	install-strip

CFLAGS+=	-Wno-error=int-conversion

.if defined(_LIMD_BINDING) && ${_LIMD_BINDING} == "py"
LIB_DEPENDS+=	libimobiledevice-1.0.so:${MASTER_PORT}
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}libplist>=2.2.0:devel/py-libplist@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}libplist>=2.2.0:devel/py-libplist@${PY_FLAVOR}

USES+=		python
USE_PYTHON=	cython3 flavors

CONFIGURE_ENV+=	PYTHON_LDFLAGS="`pkg-config --libs python-${PYTHON_VER}`"

BINARY_ALIAS=	cython=cython-${PYTHON_VER} \
		python=${PYTHON_VERSION}

BUILD_WRKSRC=	${WRKSRC}/cython
INSTALL_WRKSRC=	${BUILD_WRKSRC}
.else # parent port
LIB_DEPENDS+=	libimobiledevice-glue-1.0.so:comms/libimobiledevice-glue \
		libusbmuxd-2.0.so:comms/libusbmuxd \
		libtatsu.so:security/libtatsu

USE_LDCONFIG=	yes

CONFIGURE_ARGS+=--without-cython

PORTDOCS=	AUTHORS NEWS README.md

OPTIONS_DEFINE=	DOCS
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| *@ssl_requires@||' \
		${WRKSRC}/src/${PORTNAME}*.pc.in
.if defined(_LIMD_BINDING)
	@${REINPLACE_CMD} \
		-e 's|$$(top_builddir)/src/libimobiledevice-1.0.la|-limobiledevice-1.0|' \
		-e 's|$$(imobiledevice_la_DEPENDENCIES)||' \
		${BUILD_WRKSRC}/Makefile.in
.endif

post-install:
.if defined(_LIMD_BINDING) && ${_LIMD_BINDING} == "py"
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/imobiledevice/cython
	${INSTALL_DATA} ${INSTALL_WRKSRC}/imobiledevice.pxd \
		${STAGEDIR}${PREFIX}/include/imobiledevice/cython
.else # parent port
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
