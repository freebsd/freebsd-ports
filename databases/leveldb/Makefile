# New ports collection makefile for:	leveldb
# Date created:		2011-10-04
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	leveldb
PORTVERSION=	1.2.20111024
CATEGORIES=	databases
MASTER_SITES=	LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A fast and lightweight key/value database library by Google

OPTIONS=	PERFTOOLS	"Build with Google perftools" on \
		SNAPPY		"Build with snappy" on

USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_XZ=		yes

.include <bsd.port.options.mk>

.if !defined(WITHOUT_PERFTOOLS)
LIB_DEPENDS+=	tcmalloc:${PORTSDIR}/devel/google-perftools
.endif

.if !defined(WITHOUT_SNAPPY)
LIB_DEPENDS+=	snappy:${PORTSDIR}/archivers/snappy
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/build_detect_platform
.if defined(WITHOUT_PERFTOOLS)
	@${REINPLACE_CMD} -e '/^LDFLAGS=/ s| $$(GOOGLE_PERFTOOLS_LDFLAGS)||' ${WRKSRC}/Makefile
.endif
.if defined(WITHOUT_SNAPPY)
	@${REINPLACE_CMD} -e '/^LDFLAGS=/ s| $$(SNAPPY_LDFLAGS)||' ${WRKSRC}/Makefile
.endif

do-install:
	${MKDIR} ${PREFIX}/include/leveldb/ ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/include/leveldb/* ${PREFIX}/include/leveldb/
	${INSTALL_LIB} ${WRKSRC}/libleveldb.* ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/build_config.mk ${DATADIR}/
	${LN} -s libleveldb.so.0 ${PREFIX}/lib/libleveldb.so

.include <bsd.port.mk>
