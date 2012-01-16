# New ports collection makefile for:	tbb
# Date created:				30 Sept 2007
# Whom:					Arun Sharma <arun@sharma-home.net>
#
# $FreeBSD$
#

PORTNAME=	tbb
PORTVERSION=	4.0.0
CATEGORIES=	devel
MASTER_SITES=	http://threadingbuildingblocks.org/uploads/78/174/4.0/ \
		LOCAL/martymac
DISTNAME=	tbb40_233oss_src
EXTRACT_SUFX=	.tgz

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	A library that provides thread building blocks

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64 i386 ia64
ONLY_FOR_ARCHS_REASON=	has not been ported to this platform
USE_LDCONFIG=	yes
USE_GMAKE=	yes
ALL_TARGET=	default
MAKE_ENV=	CPLUS=${CXX}

WRKSRC=	${WRKDIR}/tbb40_233oss

post-extract:
	@${CP} ${FILESDIR}/version_info_FreeBSD.sh ${WRKSRC}/build/

post-patch:
	@${REINPLACE_CMD} 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/build/FreeBSD.gcc.inc

do-install:
	cd ${WRKSRC}; \
	${INSTALL_DATA} build/FreeBSD*release/libtbb.so \
		${PREFIX}/lib/libtbb.so.4; \
	${LN} -fs ${PREFIX}/lib/libtbb.so.4 ${PREFIX}/lib/libtbb.so; \
	${INSTALL_DATA} build/FreeBSD*release/libtbbmalloc.so \
		${PREFIX}/lib/libtbbmalloc.so.4; \
	${LN} -fs ${PREFIX}/lib/libtbbmalloc.so.4 ${PREFIX}/lib/libtbbmalloc.so; \
	${MKDIR} ${PREFIX}/include/tbb/; \
	cd include/tbb/ && ${COPYTREE_SHARE} \* ${PREFIX}/include/tbb/

.include <bsd.port.mk>
