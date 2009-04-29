# New ports collection makefile for:	tbb
# Date created:				30 Sept 2007
# Whom:					Arun Sharma <arun@sharma-home.net>
#
# $FreeBSD$
#

PORTNAME=	tbb
PORTVERSION=	2.1
CATEGORIES=	devel
MASTER_SITES=	http://www.threadingbuildingblocks.org/uploads/77/111/2.1/
DISTNAME=	tbb21_20080605oss_src
EXTRACT_SUFX=	.tgz

MAINTAINER=	arun@FreeBSD.org
COMMENT=	A library that provides thread building blocks

ONLY_FOR_ARCHS=	amd64 i386 ia64
ONLY_FOR_ARCHS_REASON=	has not been ported to this platform
USE_LDCONFIG=	yes
USE_GMAKE=	yes
ALL_TARGET=	default

WRKSRC=	${WRKDIR}/tbb21_20080605oss

post-extract:
	@${CP} ${FILESDIR}/version_info_FreeBSD.sh ${WRKSRC}/build/

post-patch:
	@${REINPLACE_CMD} 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/build/FreeBSD.gcc.inc

do-install:
	cd ${WRKSRC}; \
	${INSTALL_DATA} build/FreeBSD*release/libtbb.so \
		${PREFIX}/lib/libtbb.so; \
	${INSTALL_DATA} build/FreeBSD*release/libtbbmalloc.so \
		${PREFIX}/lib/libtbbmalloc.so; \
	${MKDIR} ${PREFIX}/include/tbb/; \
	cd include/tbb/ && ${COPYTREE_SHARE} \* ${PREFIX}/include/tbb/

.include <bsd.port.mk>
