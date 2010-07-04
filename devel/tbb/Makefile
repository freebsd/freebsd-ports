# New ports collection makefile for:	tbb
# Date created:				30 Sept 2007
# Whom:					Arun Sharma <arun@sharma-home.net>
#
# $FreeBSD$
#

PORTNAME=	tbb
PORTVERSION=	3.0
CATEGORIES=	devel
MASTER_SITES=	http://www.threadingbuildingblocks.org/uploads/78/154/3.0/
DISTNAME=	tbb30_018oss_src
EXTRACT_SUFX=	.tgz

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	A library that provides thread building blocks

ONLY_FOR_ARCHS=	amd64 i386 ia64
ONLY_FOR_ARCHS_REASON=	has not been ported to this platform
USE_LDCONFIG=	yes
USE_GMAKE=	yes
ALL_TARGET=	default

WRKSRC=	${WRKDIR}/tbb30_018oss

post-extract:
	@${CP} ${FILESDIR}/version_info_FreeBSD.sh ${WRKSRC}/build/

post-patch:
	@${REINPLACE_CMD} 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/build/FreeBSD.gcc.inc

do-install:
	cd ${WRKSRC}; \
	${INSTALL_DATA} build/FreeBSD*release/libtbb.so \
		${PREFIX}/lib/libtbb.so.3; \
	${LN} -fs ${PREFIX}/lib/libtbb.so.3 ${PREFIX}/lib/libtbb.so; \
	${INSTALL_DATA} build/FreeBSD*release/libtbbmalloc.so \
		${PREFIX}/lib/libtbbmalloc.so.3; \
	${LN} -fs ${PREFIX}/lib/libtbbmalloc.so.3 ${PREFIX}/lib/libtbbmalloc.so; \
	${MKDIR} ${PREFIX}/include/tbb/; \
	cd include/tbb/ && ${COPYTREE_SHARE} \* ${PREFIX}/include/tbb/

.include <bsd.port.mk>
