# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	eblob
PORTVERSION=	0.18.2
PORTREVISION=	7
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Append-only low-level I/O library

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	zloidemon
GH_TAGNAME=	0a75b89

USES=		cmake
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	ASSERT PYTHON SNAPPY EXAMPLES TESTS
OPTIONS_DEFAULT=PYTHON SNAPPY TESTS
TESTS_DESC=	Build tests

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MASSERT}
CMAKE_ARGS+=	-DWITH_ASSERTS=ON
.else
CMAKE_ARGS+=	-DWITH_ASSERTS=OFF
.endif

.if ${PORT_OPTIONS:MPYTHON}
LIB_DEPENDS+=	libboost_python.so:devel/boost-python-libs
USES+=		python
CMAKE_ARGS+=	-DWITH_PYTHON=ON
PLIST_SUB+=	PYTHON="" PYTHON_VER=${PYTHON_VER}
.else
CMAKE_ARGS+=	-DWITH_PYTHON=OFF
PLIST_SUB+=	PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MSNAPPY}
LIB_DEPENDS+=	libsnappy.so:archivers/snappy
CMAKE_ARGS+=	-DWITH_SNAPPY=ON
.else
CMAKE_ARGS+=	-DWITH_SNAPPY=OFF
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
CMAKE_ARGS+=	-DWITH_EXAMPLES=ON
PLIST_SUB+=	EXAMPLES=""
.else
CMAKE_ARGS+=	-DWITH_EXAMPLES=OFF
PLIST_SUB+=	EXAMPLES="@comment "
.endif

.if ${PORT_OPTIONS:MTESTS}
CMAKE_ARGS+=	-DWITH_TESTS=ON
.else
CMAKE_ARGS+=	-DWITH_TESTS=OFF
.endif

post-patch:
.if ! ${PORT_OPTIONS:MPYTHON}
	@${REINPLACE_CMD} -e 's, python),),' ${WRKSRC}/CMakeLists.txt
.else
	@${REINPLACE_CMD} -e 's,$$ENV{DESTDIR},${STAGEDIR},' \
		${WRKSRC}/bindings/python/python/CMakeLists.txt
.endif
	@${REINPLACE_CMD} -e 's, -fstack-protector-all,,' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
