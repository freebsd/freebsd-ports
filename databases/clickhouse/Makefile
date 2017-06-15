# Created by: proler@gmail.com
# $FreeBSD$

PORTNAME=	clickhouse
PORTVERSION=	1.1.54165
PORTREVISION=	1
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-stable
CATEGORIES=	databases

MAINTAINER=	proler@gmail.com
COMMENT=	ClickHouse is an column-oriented database management system

LICENSE=	APACHE20

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libsqlite3.so:databases/sqlite3 \
		libtcmalloc.so:devel/google-perftools \
		libodbc.so:databases/unixODBC \
		libltdl.so:devel/libltdl \
		libicudata.so:devel/icu \
		libboost_program_options.so:devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	yandex
GH_PROJECT=	ClickHouse

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	"Only supported on amd64"

USES=		compiler:c++14-lang cmake iconv mysql ssl readline
USE_LDCONFIG=	yes
CMAKE_ARGS=	-DUSE_INTERNAL_GPERFTOOLS_LIBRARY=0 \
		-DUSE_INTERNAL_BOOST_LIBRARY=0 \
		-DUSE_INTERNAL_ZLIB_LIBRARY=0 \
		-DUSE_STATIC_LIBRARIES=0 \
		-DNO_WERROR=1

USE_RC_SUBR=	${PORTNAME}
USERS=		clickhouse
GROUPS=		clickhouse

#temporary! use PORTVERSION after version match
SOVERSION=	1.1.54164
PLIST_SUB=	SOVERSION=${SOVERSION}

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1100000
BUILD_DEPENDS+= clang38:devel/llvm38
CC=		clang38
CXX=		clang++38
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/var/lib/clickhouse|/var/db/clickhouse|' ${WRKSRC}/dbms/src/Server/config.xml

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/clickhouse-compressor
	@${RM} ${STAGEDIR}${PREFIX}/bin/config-processor
	@${RM} ${STAGEDIR}${PREFIX}/bin/corrector_utf8
	@${RM} ${STAGEDIR}${PREFIX}/lib/cmake/Poco/PocoConfig.cmake
	@${RMDIR} ${STAGEDIR}${PREFIX}/lib/cmake/Poco
	@${RMDIR} ${STAGEDIR}${PREFIX}/lib/cmake

	${INSTALL_DATA} ${WRKSRC}/dbms/src/Client/config.xml \
		${STAGEDIR}${PREFIX}/etc/clickhouse-client/config.xml.sample
	${INSTALL_DATA} ${WRKSRC}/dbms/src/Server/config.xml \
		${STAGEDIR}${PREFIX}/etc/clickhouse-server/config.xml.sample
	${INSTALL_DATA} ${WRKSRC}/dbms/src/Server/users.xml \
		${STAGEDIR}${PREFIX}/etc/clickhouse-server/users.xml.sample

	@${MKDIR} ${STAGEDIR}/var/db/clickhouse
	@${MKDIR} ${STAGEDIR}/var/log/clickhouse
	@${MKDIR} ${STAGEDIR}/var/run/clickhouse

.include <bsd.port.post.mk>
