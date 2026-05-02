PORTNAME=	brpc
DISTVERSION=	1.16.0
CATEGORIES=	devel

MAINTAINER=	daniel@morante.net
COMMENT=	Apache bRPC - Industrial-grade RPC framework
WWW=		https://brpc.apache.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/gtest/gtest.h:devel/googletest
LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libgflags.so:devel/gflags \
		libleveldb.so:databases/leveldb \
		libprotobuf.so:devel/protobuf

USES=		cmake:noninja localbase:ldflags ssl
USE_GITHUB=	yes
GH_ACCOUNT=	apache

CMAKE_ARGS=	-DBUILD_BRPC_TOOLS=ON

PLIST_SUB=	VERSION=${PORTVERSION}

OPTIONS_DEFINE=	GLOG
OPTIONS_DEFAULT=

GLOG_DESC=	Use Google glog for logging
GLOG_LIB_DEPENDS=	libglog.so:devel/glog
GLOG_CMAKE_BOOL=	WITH_GLOG
GLOG_CXXFLAGS=		-DGLOG_USE_GLOG_EXPORT

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/parallel_http
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rpc_press
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rpc_replay
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rpc_view
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/trackme_server

.include <bsd.port.mk>
