# Created by: Valery Komarov <komarov@valerka.net>
# $FreeBSD$

PORTNAME=	thrift
PORTVERSION=	${THRIFT_PORTVERSION} # to keep in sync with thrift
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	devel
PKGNAMESUFFIX=	-cpp
MASTER_SITES=		APACHE/thrift/${PORTVERSION}
DISTNAME=		thrift-${PORTVERSION}

MAINTAINER=	komarov@valerka.net
COMMENT=	C++ interface to Thrift

DISTINFO_FILE=		${.CURDIR}/../thrift/distinfo

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libevent.so:devel/libevent2

USES=			autoreconf pkgconfig gmake compiler:c++11-lang libtool
GNU_CONFIGURE=		yes
USE_LDCONFIG=		yes
MAKE_JOBS_UNSAFE=	yes
PLIST_SUB=		PORTVERSION="${THRIFT_PORTVERSION}"
USE_OPENSSL=		yes

OPTIONS_DEFINE=		QT4
QT4_CONFIGURE_WITH=	qt4
QT4_USE=		QT4=network,moc_build,qmake_build,rcc_build,uic_build

OPTIONS_SUB=		yes

CONFIGURE_ARGS+=	\
		--without-c_glib \
		--with-cpp \
		--without-csharp \
		--without-erlang \
		--without-haskell \
		--without-java \
		--without-perl \
		--without-php \
		--without-php_extension \
		--without-python \
		--without-ruby \
		--without-go

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base && \
	${OPSYS} == FreeBSD && ${OSVERSION} < 1000015
# src/thrift/transport/TSSLSocket.cpp:147: error: 'TLSv1_1_method' was not declared in this scope
# src/thrift/transport/TSSLSocket.cpp:149: error: 'TLSv1_2_method' was not declared in this scope
BROKEN=		does not build with 9.x base OpenSSL
.endif

.if ${COMPILER_TYPE} == clang
USE_CXXSTD=	c++11
.endif

post-patch:
	@${REINPLACE_CMD} 's,^pkgconfigdir = .*,pkgconfigdir=$${prefix}/libdata/pkgconfig,' ${WRKSRC}/lib/cpp/Makefile.am

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so
	${LN} -sf libthrift-${PORTVERSION}.so ${STAGEDIR}${PREFIX}/lib/libthrift.so.0
	${LN} -sf libthriftnb-${PORTVERSION}.so ${STAGEDIR}${PREFIX}/lib/libthriftnb.so.0
	${LN} -sf libthriftz-${PORTVERSION}.so ${STAGEDIR}${PREFIX}/lib/libthriftz.so.0

post-install-QT4-on:
	${LN} -sf libthriftqt-${PORTVERSION}.so ${STAGEDIR}${PREFIX}/lib/libthriftqt.so.0

.include "../thrift/bsd.thrift.mk"
.include <bsd.port.post.mk>
