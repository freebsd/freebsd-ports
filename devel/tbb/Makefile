# Created by: Arun Sharma <arun@sharma-home.net>
# $FreeBSD$

PORTNAME=	tbb
PORTVERSION=	4.1.2
CATEGORIES=	devel
MASTER_SITES=	http://threadingbuildingblocks.org/sites/default/files/software_releases/source/ \
		LOCAL/martymac
DISTNAME=	tbb41_20130116oss_src
EXTRACT_SUFX=	.tgz

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	A library that provides thread building blocks

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64 i386 ia64
ONLY_FOR_ARCHS_REASON=	has not been ported to this platform

USE_LDCONFIG=	yes
USE_GMAKE=	yes
ALL_TARGET=	default

WRKSRC=	${WRKDIR}/tbb41_20130116oss

post-extract:
	@${CP} ${WRKSRC}/build/FreeBSD.gcc.inc ${WRKSRC}/build/FreeBSD.${CC}.inc
	@${CP} ${FILESDIR}/version_info_FreeBSD.sh ${WRKSRC}/build/

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|g' -e 's|g++|${CXX}|g' \
		${WRKSRC}/build/FreeBSD.${CC}.inc

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
