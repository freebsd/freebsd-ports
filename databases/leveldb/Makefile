# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	leveldb
PORTVERSION=	1.12.0
CATEGORIES=	databases
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast and lightweight key/value database library by Google

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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGPERFTOOLS}
LIB_DEPENDS+=	tcmalloc:${PORTSDIR}/devel/google-perftools
.endif

.if ${PORT_OPTIONS:MSNAPPY}
LIB_DEPENDS+=	snappy:${PORTSDIR}/archivers/snappy
SNAPPY=		1
.else
SNAPPY=		0
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/build_detect_platform
.if empty(PORT_OPTIONS:MGPERFTOOLS)
	@${REINPLACE_CMD} -e 's| -ltcmalloc||' ${WRKSRC}/build_detect_platform
.endif
.if empty(PORT_OPTIONS:MSNAPPY)
	@${REINPLACE_CMD} -e 's| -DSNAPPY||; s| -lsnappy||' ${WRKSRC}/build_detect_platform
.endif

do-install:
	${MKDIR} ${PREFIX}/include/leveldb/ ${PREFIX}/include/memenv/ ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/include/leveldb/* ${PREFIX}/include/leveldb/
	${INSTALL_DATA} ${WRKSRC}/helpers/memenv/memenv.h ${PREFIX}/include/memenv/
	${INSTALL_LIB} ${WRKSRC}/libleveldb.a ${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/libleveldb.so.${SHLIB_MAJOR}.${SHLIB_MINOR} ${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/libmemenv.a ${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/libmemenv.so.${SHLIB_MAJOR}.${SHLIB_MINOR} ${PREFIX}/lib/
	${LN} -s libleveldb.so.${SHLIB_MAJOR} ${PREFIX}/lib/libleveldb.so
	${LN} -s libleveldb.so.${SHLIB_MAJOR}.${SHLIB_MINOR} ${PREFIX}/lib/libleveldb.so.${SHLIB_MAJOR}
	${LN} -s libmemenv.so.${SHLIB_MAJOR} ${PREFIX}/lib/libmemenv.so
	${LN} -s libmemenv.so.${SHLIB_MAJOR}.${SHLIB_MINOR} ${PREFIX}/lib/libmemenv.so.${SHLIB_MAJOR}
# backward compatibility
	${ECHO} "SNAPPY=${SNAPPY}" >> ${WRKSRC}/build_config.mk
	${GREP} '^PLATFORM_CXXFLAGS=' ${WRKSRC}/build_config.mk | ${SED} 's|PLATFORM_CXXFLAGS|PORT_CFLAGS|' >> ${WRKSRC}/build_config.mk
	${GREP} '^PLATFORM_CXXFLAGS=' ${WRKSRC}/build_config.mk | ${SED} 's|PLATFORM_CXXFLAGS|PLATFORM_CFLAGS|' >> ${WRKSRC}/build_config.mk
	${INSTALL_DATA} ${WRKSRC}/build_config.mk ${DATADIR}/

.include <bsd.port.mk>
