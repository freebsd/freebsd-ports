# New ports collection makefile for:	tbb
# Date created:				30 Sept 2007
# Whom:					Arun Sharma <arun@sharma-home.net>
#
# $FreeBSD$
#

PORTNAME=	tbb
PORTVERSION=	2.0
CATEGORIES=	devel
MASTER_SITES=	http://threadingbuildingblocks.org/uploads/76/95/2.0/
DISTNAME=	tbb20_20080207oss_src

MAINTAINER=	arun@FreeBSD.org
COMMENT=	A library that provides thread building blocks

PATCH_STRIP=	-p1

ONLY_FOR_ARCHS=	amd64 i386 ia64
ONLY_FOR_ARCHS_REASON=	has not been ported to this platform
USE_LDCONFIG=	yes
USE_GMAKE=	yes
ALL_TARGET=	default

do-install:
	cd ${WRKSRC}; \
	${INSTALL_DATA} build/FreeBSD*release/libtbb.so \
		${PREFIX}/lib/libtbb.so; \
	${INSTALL_DATA} build/FreeBSD*release/libtbbmalloc.so \
		${PREFIX}/lib/libtbbmalloc.so; \
	${MKDIR} ${PREFIX}/include/tbb/machine; \
	${FIND} include -type f -name '*.h' -exec \
		${INSTALL_DATA} \{\} ${PREFIX}/\{\} \;

.include <bsd.port.mk>
