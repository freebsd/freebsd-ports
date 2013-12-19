# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	leveldb
PORTVERSION=	1.15.0
CATEGORIES=	databases
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast and lightweight key/value database library by Google

LICENSE=	BSD3CLAUSE

OPTIONS_DEFINE=	GPERFTOOLS SNAPPY
OPTIONS_DEFAULT=SNAPPY

LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
USES=		gmake

PLIST_SUB=	SHLIB_MAJOR=${SHLIB_MAJOR} \
		SHLIB_MINOR=${SHLIB_MINOR}

NOT_FOR_ARCHS=	powerpc
NOT_FOR_ARCHS_REASON=	not yet ported to this platform

SHLIB_MAJOR=	${PORTVERSION:R:R}
SHLIB_MINOR=	${PORTVERSION:R:E}

GPERFTOOLS_LIB_DEPENDS=	libtcmalloc.so:${PORTSDIR}/devel/google-perftools
SNAPPY_LIB_DEPENDS=	libsnappy.so:${PORTSDIR}/archivers/snappy

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSNAPPY}
SNAPPY=		1
.else
SNAPPY=		0
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|-pthread|' ${WRKSRC}/build_detect_platform
.if !${PORT_OPTIONS:MGPERFTOOLS}
	@${REINPLACE_CMD} -e 's| -ltcmalloc||' ${WRKSRC}/build_detect_platform
.endif
.if !${PORT_OPTIONS:MSNAPPY}
	@${REINPLACE_CMD} -e 's| -DSNAPPY||; s| -lsnappy||' ${WRKSRC}/build_detect_platform
.endif

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/leveldb/ ${STAGEDIR}${PREFIX}/include/memenv/ ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/include/leveldb/* ${STAGEDIR}${PREFIX}/include/leveldb/
	${INSTALL_DATA} ${WRKSRC}/helpers/memenv/memenv.h ${STAGEDIR}${PREFIX}/include/memenv/
	${INSTALL_LIB} ${WRKSRC}/libleveldb.a ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/libleveldb.so.${SHLIB_MAJOR}.${SHLIB_MINOR} ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/libmemenv.a ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/libmemenv.so.${SHLIB_MAJOR}.${SHLIB_MINOR} ${STAGEDIR}${PREFIX}/lib/
	${LN} -fs libleveldb.so.${SHLIB_MAJOR} ${STAGEDIR}${PREFIX}/lib/libleveldb.so
	${LN} -fs libleveldb.so.${SHLIB_MAJOR}.${SHLIB_MINOR} ${STAGEDIR}${PREFIX}/lib/libleveldb.so.${SHLIB_MAJOR}
	${LN} -fs libmemenv.so.${SHLIB_MAJOR} ${STAGEDIR}${PREFIX}/lib/libmemenv.so
	${LN} -fs libmemenv.so.${SHLIB_MAJOR}.${SHLIB_MINOR} ${STAGEDIR}${PREFIX}/lib/libmemenv.so.${SHLIB_MAJOR}
# backward compatibility
	${ECHO} "SNAPPY=${SNAPPY}" >> ${WRKSRC}/build_config.mk
	${GREP} '^PLATFORM_CXXFLAGS=' ${WRKSRC}/build_config.mk | ${SED} 's|PLATFORM_CXXFLAGS|PORT_CFLAGS|' >> ${WRKSRC}/build_config.mk
	${GREP} '^PLATFORM_CXXFLAGS=' ${WRKSRC}/build_config.mk | ${SED} 's|PLATFORM_CXXFLAGS|PLATFORM_CFLAGS|' >> ${WRKSRC}/build_config.mk
	${INSTALL_DATA} ${WRKSRC}/build_config.mk ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
