# New ports collection makefile for:	leveldb
# Date created:		2011-10-04
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	leveldb
PORTVERSION=	1.2.20111114
CATEGORIES=	databases
MASTER_SITES=	LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A fast and lightweight key/value database library by Google

OPTIONS=	PERFTOOLS	"Build with Google perftools" off \
		SNAPPY		"Build with snappy" on

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_XZ=		yes

.include <bsd.port.options.mk>

.if defined(WITH_PERFTOOLS)
LIB_DEPENDS+=	tcmalloc:${PORTSDIR}/devel/google-perftools
.endif

.if !defined(WITHOUT_SNAPPY)
LIB_DEPENDS+=	snappy:${PORTSDIR}/archivers/snappy
.endif

NOT_FOR_ARCHS=		powerpc
NOT_FOR_ARCHS_REASON=	not yet ported to this platform

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/build_detect_platform
.if !defined(WITH_PERFTOOLS)
	@${REINPLACE_CMD} -e '/^GOOGLE_PERFTOOLS_LDFLAGS=/ s|=.*|=|' ${WRKSRC}/Makefile
.endif
.if defined(WITHOUT_SNAPPY)
	@${REINPLACE_CMD} -e '/^SNAPPY_LDFLAGS=/ s|=.*|=|' ${WRKSRC}/Makefile
.endif

do-install:
	${MKDIR} ${PREFIX}/include/leveldb/ ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/include/leveldb/* ${PREFIX}/include/leveldb/
	${INSTALL_LIB} ${WRKSRC}/libleveldb.* ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/build_config.mk ${DATADIR}/
	${LN} -s libleveldb.so.0 ${PREFIX}/lib/libleveldb.so

.include <bsd.port.mk>
