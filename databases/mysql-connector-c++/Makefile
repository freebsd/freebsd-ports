PORTNAME=	mysql-connector-c++
DISTVERSION=	9.4.0
CATEGORIES=	databases
MASTER_SITES=	MYSQL/Connector-C++
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	MySQL database connector for C++
WWW=		https://dev.mysql.com/doc/relnotes/connector-cpp/en/index.html

LICENSE=	GPLv2 # only
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs \
		liblz4.so:archivers/liblz4 \
		libprotobuf.so:devel/protobuf \
		libzstd.so:archivers/zstd

USES=		cmake:noninja compiler:c++17-lang cpe gmake mysql ssl
IGNORE_WITH_MYSQL=	105m 106m 1011m
CPE_VENDOR=	oracle
USE_CXXSTD=	c++17
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_ENABLE_C++17=ON \
		-DWITH_LZ4=system \
		-DWITH_PROTOBUF=system \
		-DWITH_SYSTEM_LIBS=1 \
		-DWITH_ZLIB=system \
		-DWITH_ZSTD=system

PLIST_SUB=	PORTVERSION=${DISTVERSION}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS JDBC
OPTIONS_DEFAULT=	JDBC
OPTIONS_SUB=	yes

JDBC_DESC=	Build  JDBC Interface

DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen
DOCS_CMAKE_ON=		-DDOC_DESTINATION="${DOCSDIR}" \
			-DWITH_DOC=ON
JDBC_LIB_DEPENDS=	libunwind.so:devel/libunwind
JDBC_CMAKE_ON=		-DWITH_JDBC=ON

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/INFO_BIN
	@${RM} ${STAGEDIR}${PREFIX}/INFO_SRC
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/cmake
	@${MV} ${STAGEDIR}${PREFIX}/mysql-*.cmake \
		${STAGEDIR}${PREFIX}/lib/cmake/

post-install-DOCS-on:
	@${RM} ${STAGEDIR}${DOCSDIR}/INSTALL \
		${STAGEDIR}${DOCSDIR}/LICENSE.txt
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${BUILD_WRKSRC}/doc && \
		${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
