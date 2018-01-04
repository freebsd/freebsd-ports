# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	leveldb
PORTVERSION=	1.20
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast and lightweight key/value database library by Google

LICENSE=	BSD3CLAUSE

OPTIONS_DEFINE=	GPERFTOOLS SNAPPY
OPTIONS_DEFAULT=SNAPPY

CONFIGURE_ARGS=	build_config.mk ${WRKSRC}/
CONFIGURE_SCRIPT=	build_detect_platform
HAS_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
TEST_TARGET=	check
USE_LDCONFIG=	yes
USES=		compiler:c++0x gmake localbase

PLIST_SUB=	SHLIB_MAJOR=${SHLIB_MAJOR} \
		SHLIB_MINOR=${SHLIB_MINOR}

SHLIB_MAJOR=	${PORTVERSION:R}
SHLIB_MINOR=	${PORTVERSION:E}

GH_ACCOUNT=	google
USE_GITHUB=	yes

GPERFTOOLS_LIB_DEPENDS=	libtcmalloc.so:devel/google-perftools
SNAPPY_LIB_DEPENDS=	libsnappy.so:archivers/snappy

post-patch:
	@${REINPLACE_CMD} -e '/PLATFORM_IS_LITTLE_ENDIAN/ s|__|_|g' ${WRKSRC}/port/port_posix.h

post-patch-GPERFTOOLS-off:
	@${REINPLACE_CMD} -e 's| -ltcmalloc||' ${WRKSRC}/build_detect_platform

post-patch-SNAPPY-off:
	@${REINPLACE_CMD} -e 's| -DSNAPPY||; s| -lsnappy||' ${WRKSRC}/build_detect_platform

# backward compatibility (for databases/p5-Tie-LevelDB)
pre-install-SNAPPY-off:
	${ECHO_CMD} "SNAPPY=0" >> ${WRKSRC}/build_config.mk

pre-install-SNAPPY-on:
	${ECHO_CMD} "SNAPPY=1" >> ${WRKSRC}/build_config.mk

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/leveldb/ ${STAGEDIR}${PREFIX}/include/memenv/ ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/include/leveldb/* ${STAGEDIR}${PREFIX}/include/leveldb/
	${INSTALL_DATA} ${WRKSRC}/helpers/memenv/memenv.h ${STAGEDIR}${PREFIX}/include/memenv/
	${INSTALL_LIB} ${WRKSRC}/out-shared/libleveldb.so.${SHLIB_MAJOR}.${SHLIB_MINOR} ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/out-shared/libmemenv.so.${SHLIB_MAJOR}.${SHLIB_MINOR} ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/out-static/libleveldb.a ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/out-static/libmemenv.a ${STAGEDIR}${PREFIX}/lib/
	${LN} -fs libleveldb.so.${SHLIB_MAJOR} ${STAGEDIR}${PREFIX}/lib/libleveldb.so
	${LN} -fs libleveldb.so.${SHLIB_MAJOR}.${SHLIB_MINOR} ${STAGEDIR}${PREFIX}/lib/libleveldb.so.${SHLIB_MAJOR}
	${LN} -fs libmemenv.so.${SHLIB_MAJOR} ${STAGEDIR}${PREFIX}/lib/libmemenv.so
	${LN} -fs libmemenv.so.${SHLIB_MAJOR}.${SHLIB_MINOR} ${STAGEDIR}${PREFIX}/lib/libmemenv.so.${SHLIB_MAJOR}
# backward compatibility (for databases/p5-Tie-LevelDB)
	${GREP} '^PLATFORM_CXXFLAGS=' ${WRKSRC}/build_config.mk | ${SED} 's|PLATFORM_CXXFLAGS|PORT_CFLAGS|' >> ${WRKSRC}/build_config.mk
	${GREP} '^PLATFORM_CXXFLAGS=' ${WRKSRC}/build_config.mk | ${SED} 's|PLATFORM_CXXFLAGS|PLATFORM_CFLAGS|' >> ${WRKSRC}/build_config.mk
	${INSTALL_DATA} ${WRKSRC}/build_config.mk ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
