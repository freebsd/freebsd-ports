# Created by: proler@gmail.com
# $FreeBSD$

PORTNAME=	clickhouse
PORTVERSION=	1.1.54245
PORTREVISION=	1
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-stable
#PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	proler@gmail.com
COMMENT=	ClickHouse is an column-oriented database management system

LICENSE=	APACHE20

BROKEN=		fails to build

BUILD_DEPENDS=	bash:shells/bash \
				sparsehash>=0:devel/sparsehash
LIB_DEPENDS=	libtcmalloc.so:devel/google-perftools \
		libodbc.so:databases/unixODBC \
		libltdl.so:devel/libltdl \
		libicudata.so:devel/icu \
		libzookeeper_mt.so:devel/libzookeeper \
		libre2.so:devel/re2 \
		libdouble-conversion.so:devel/libdouble-conversion \
		libzstd.so:archivers/zstd \
		liblz4.so:archivers/liblz4 \
		libPocoNet.so:devel/poco

USE_GITHUB=	yes
GH_ACCOUNT=	yandex
GH_PROJECT=	ClickHouse

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	"Only supported on amd64"

BROKEN_FreeBSD_10=	Builds but does not work

USES=		compiler:c++14-lang cmake iconv mysql ssl readline
USE_LDCONFIG=	yes
# Bug 218841: use bundled boost 1.62 to avoid 1.64 bustage
CMAKE_ARGS=	-DUNBUNDLED=1 \
		-DUSE_INTERNAL_BOOST_LIBRARY=1 \
		-DUSE_STATIC_LIBRARIES=0 \
		-DNO_WERROR=1 \
		-DENABLE_TESTS=0 \
		-DCXX11_ABI=

USE_RC_SUBR=	${PORTNAME}
USERS=		clickhouse
GROUPS=		clickhouse

SOVERSION=	${PORTVERSION}
PLIST_SUB=	SOVERSION=${SOVERSION}

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1100000
BUILD_DEPENDS+=	clang38:devel/llvm38
CC=		clang38
CXX=		clang++38
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/var/lib/clickhouse|/var/db/clickhouse|;s|/var/log/clickhouse-server|/var/log/clickhouse|;s|/etc/clickhouse-server|${PREFIX}/etc/clickhouse-server|' ${WRKSRC}/dbms/src/Server/config.xml
	@${REINPLACE_CMD} -e 's|<listen_host>::1</listen_host>|<\!-- <listen_host>::1</listen_host> -->|;s|<listen_host>127.0.0.1</listen_host>|<\!-- <listen_host>127.0.0.1</listen_host> -->|' ${WRKSRC}/dbms/src/Server/config.xml

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/clickhouse-compressor
	@${RM} ${STAGEDIR}${PREFIX}/bin/config-processor
	@${RM} ${STAGEDIR}${PREFIX}/bin/corrector_utf8
	@${RM} -r ${STAGEDIR}${PREFIX}/include/gtest
	@${RM} ${STAGEDIR}${PREFIX}/lib/libgtest*

	${INSTALL_DATA} ${STAGEDIR}${PREFIX}/etc/clickhouse-client/config.xml \
		${STAGEDIR}${PREFIX}/etc/clickhouse-client/config.xml.sample
	${INSTALL_DATA} ${STAGEDIR}${PREFIX}/etc/clickhouse-server/config.xml \
		${STAGEDIR}${PREFIX}/etc/clickhouse-server/config.xml.sample
	${INSTALL_DATA} ${STAGEDIR}${PREFIX}/etc/clickhouse-server/users.xml \
		${STAGEDIR}${PREFIX}/etc/clickhouse-server/users.xml.sample

	@${MKDIR} ${STAGEDIR}/var/db/clickhouse
	@${MKDIR} ${STAGEDIR}/var/log/clickhouse
	@${MKDIR} ${STAGEDIR}/var/run/clickhouse

.include <bsd.port.post.mk>
