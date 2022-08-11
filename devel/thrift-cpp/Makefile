PORTNAME=	thrift
PORTVERSION=	${THRIFT_PORTVERSION} # to keep in sync with thrift
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	APACHE/thrift/${PORTVERSION}
PKGNAMESUFFIX=	-cpp
DISTNAME=	thrift-${PORTVERSION}

MAINTAINER=	komarov@valerka.net
COMMENT=	C++ interface to Thrift

BROKEN_i386=	undefined reference to 'boost::atomics::detail::lockpool::scoped_lock::scoped_lock(void const volatile*)'

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libevent.so:devel/libevent

DISTINFO_FILE=		${.CURDIR}/../thrift/distinfo

USES=			bison cmake pkgconfig compiler:c++11-lang cpe \
			libtool pathfix ssl
CPE_VENDOR=		apache
USE_LDCONFIG=		yes
MAKE_JOBS_UNSAFE=	yes
PLIST_SUB=		PORTVERSION="${THRIFT_PORTVERSION}"
CMAKE_ON=	BUILD_CPP BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_C_GLIB BUILD_JAVA BUILD_JAVASCRIPT BUILD_NODEJS BUILD_PYTHON BUILD_HASKELL

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
USE_CXXSTD=	c++11
.endif

.if ${SSL_DEFAULT} != base
LDFLAGS+=	-L${OPENSSLLIB}
CFLAGS+=	-I${OPENSSLINC}
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so
	${LN} -sf libthrift-${PORTVERSION}.so ${STAGEDIR}${PREFIX}/lib/libthrift.so.0
	${LN} -sf libthriftnb-${PORTVERSION}.so ${STAGEDIR}${PREFIX}/lib/libthriftnb.so.0
	${LN} -sf libthriftz-${PORTVERSION}.so ${STAGEDIR}${PREFIX}/lib/libthriftz.so.0

.include "../thrift/bsd.thrift.mk"
.include <bsd.port.post.mk>
