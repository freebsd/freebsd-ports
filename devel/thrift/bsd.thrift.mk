# to use:
# in your makefile, set:
# PORTVERSION=	${THRIFT_PORTVERSION}
# see $PORTSDIR/devel/thrift for examples 
THRIFT_PORTVERSION=	0.22.0

LICENSE=		APACHE20

MASTER_SITE_APACHE+=	https://archive.apache.org/dist/%SUBDIR%/ 
CONFIGURE_ARGS+=	\
		--without-tests

# Make sure we install thrift compiler related files not with child packages
.if !empty(PKGNAMESUFFIX) || ${PORTNAME} != "thrift"
_USES_install+= 900:thrift-post-install
BUILD_DEPENDS+=	thrift>=${PORTVERSION}:devel/thrift
RUN_DEPENDS+=	thrift>=${PORTVERSION}:devel/thrift

CMAKE_ARGS+=	-DTHRIFT_COMPILER=${PREFIX}/bin/thrift
CMAKE_ON+=	BUILD_SHARED_LIBS
CMAKE_OFF+=	BUILD_COMPILER

thrift-post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib/cmake/thrift/FindLibevent.cmake
	${RM} ${STAGEDIR}${PREFIX}/lib/cmake/thrift/ThriftConfig.cmake
	${RM} ${STAGEDIR}${PREFIX}/lib/cmake/thrift/ThriftConfigVersion.cmake
.else
MAKE_ON+=	BUILD_COMPILER
CMAKE_OFF+=	BUILD_SHARED_LIB
.endif
