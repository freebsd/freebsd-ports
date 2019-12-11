# Created by: Valery Komarov <komarov@valerka.net>
# $FreeBSD$

PORTNAME=	thrift
PORTVERSION=	${THRIFT_PORTVERSION} # to keep in sync with thrift
PORTREVISION=	12
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

BROKEN_SSL=	openssl111
BROKEN_SSL_REASON_openssl111=	'configure: error: "Error: libcrypto required."'

USES=			autoreconf pkgconfig gmake compiler:c++11-lang \
			libtool pathfix ssl
GNU_CONFIGURE=		yes
USE_LDCONFIG=		yes
MAKE_JOBS_UNSAFE=	yes
PLIST_SUB=		PORTVERSION="${THRIFT_PORTVERSION}"

CONFIGURE_ARGS+=	\
		--without-c_glib \
		--with-cpp \
		--with-boost-libdir="${LOCALBASE}/lib" \
		--without-csharp \
		--without-erlang \
		--without-haskell \
		--without-java \
		--without-perl \
		--without-php \
		--without-php_extension \
		--without-python \
		--without-ruby \
		--without-lua \
		--with-qt5=no \
		--without-go

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
