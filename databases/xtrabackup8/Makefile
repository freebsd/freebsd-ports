PORTNAME=	xtrabackup
PORTVERSION=	8.0.31
DISTVERSIONSUFFIX=	-24
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	https://github.com/percona/percona-xtrabackup/archive/:percona \
		SF/boost/boost/${BOOST_VERSION}:boost
PKGNAMESUFFIX=	8
DISTFILES=	${PPORTNAME}-${DVERSION}${EXTRACT_SUFX}:percona \
		boost_${BOOST_VERSION_UNDER}${EXTRACT_SUFX}:boost

MAINTAINER=	eugene@zhegan.in
COMMENT=	Open-source backup tool for InnoDB and XtraDB
WWW=		https://www.percona.com/doc/percona-xtrabackup/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	protobuf>=3.0:devel/protobuf \
		rapidjson>=1.1.0:devel/rapidjson \
		libevent>=2.1:devel/libevent \
		ncurses>=6.3:devel/ncurses
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libev.so:devel/libev \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libicudata.so:devel/icu \
		libncurses.so.6:devel/ncurses \
		libprotobuf-lite.so:devel/protobuf \
		libunwind.so:devel/libunwind \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	qpress:archivers/qpress

USES=		bison cmake compiler:c++14-lang cpe pkgconfig ssl
CPE_VENDOR=	percona
CMAKE_ARGS=	-DBUILD_CONFIG:STRING=xtrabackup_release \
		-DWITHOUT_COMPONENT_KEYRING_KMIP:STRING=yes \
		-DWITH_VERSION_CHECK=false

.for component in EDITLINE ICU LIBEVENT PROTOBUF RAPIDJSON ZSTD
CMAKE_ARGS+=	-DWITH_${component}:STRING=system
.endfor

CONFLICTS_INSTALL=	${PORTNAME}

# Bundle last supported Boost release
BOOST_VERSION=	1.77.0
BOOST_VERSION_UNDER=	${BOOST_VERSION:C/\./_/g}

CMAKE_ARGS+=	-DWITH_BOOST=${WRKDIR}/boost_${BOOST_VERSION_UNDER}

# Build fails without NDEBUG, so force it
CFLAGS+=	-DNDEBUG
CXXFLAGS+=	-DNDEBUG

DVERSION=	${PORTVERSION}${DISTVERSIONSUFFIX}
PPORTNAME=	percona-${PORTNAME}
WRKSRC=		${WRKDIR}/${PPORTNAME}-${PPORTNAME}-${DVERSION}

.include <bsd.port.pre.mk>

# Since MySQL 8.0.20 InnoDB engine uses new memory alligned allocator
# which is broken on i386 due to different size of types and causes a
# 'static_assert(alignof(T) <= alignof(std::max_align_t))' error
.if ${ARCH} == i386
CXXFLAGS+=	-malign-double
.endif

KEEP_EXTRA=	lz4 robin-hood-hashing zlib

post-patch:
.if ${COMPILER_TYPE} == clang && ${COMPILER_VERSION} >= 160
	@${REINPLACE_CMD} -e 's|std::unary_function|std::__unary_function|' \
		${WRKSRC}/../boost_1_77_0/boost/container_hash/hash.hpp
.endif

pre-configure:
.for dir in ${KEEP_EXTRA}
	@${MV} ${WRKSRC}/extra/${dir} ${WRKDIR}
.endfor
	@${RM} -r ${WRKSRC}/extra/*
.for dir in ${KEEP_EXTRA}
	@${MV} ${WRKDIR}/${dir} ${WRKSRC}/extra
.endfor

post-stage:
	@${RM} -r ${STAGEDIR}${PREFIX}/docs
	@${RMDIR} ${STAGEDIR}${PREFIX}/lib/plugin/debug

.include <bsd.port.post.mk>
