# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	eblob
PORTVERSION=	0.17.5
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Append-only low-level I/O library

LICENSE=	GPLv2

LIB_DEPENDS=	boost_iostreams:${PORTSDIR}/devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	zloidemon
GH_COMMIT=	9c2c347
GH_TAGNAME=	master

USE_CMAKE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	ASSERT PYTHON SNAPPY EXAMPLES TESTS
OPTIONS_DEFAULT=PYTHON SNAPPY EXAMPLES TESTS
TESTS_DESC=	Build tests

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MASSERT}
CMAKE_ARGS+=	-DWITH_ASSERTS=ON
.else
CMAKE_ARGS+=	-DWITH_ASSERTS=OFF
.endif

.if ${PORT_OPTIONS:MPYTHON}
LIB_DEPENDS+=	boost_python:${PORTSDIR}/devel/boost-python-libs
USE_PYTHON=	yes
CMAKE_ARGS+=	-DWITH_PYTHON=ON
INSTALLS_EGGINFO=	yes
PYDISTUTILS_PKGVERSION=	0.0.1
PLIST_SUB+=	PYTHON=""
.else
CMAKE_ARGS+=	-DWITH_PYTHON=OFF
PLIST_SUB+=	PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MSNAPPY}
LIB_DEPENDS+=	snappy:${PORTSDIR}/archivers/snappy
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
.endif
	@${REINPLACE_CMD} -e 's, -fstack-protector-all,,' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
