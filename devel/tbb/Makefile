# New ports collection makefile for:	tbb
# Date created:				30 Sept 2007
# Whom:					Arun Sharma <arun@sharma-home.net>
#
# $FreeBSD$
#

PORTNAME=	tbb
PORTVERSION=	2.0
CATEGORIES=	devel
MASTER_SITES=	http://osstbb.intel.com/uploads/76/74/2.0/
DISTNAME=	tbb20_20070815oss_src

MAINTAINER=	arun@FreeBSD.org
COMMENT=	A library that provides thread building blocks

PATCH_STRIP=	-p1

ONLY_FOR_ARCHS=	amd64 i386 ia64
ONLY_FOR_ARCHS_REASON=	has not been ported to this platform
USE_LDCONFIG=	yes
USE_GMAKE=	yes
ALL_TARGET=	tbb_release

do-install:
	cd ${WRKSRC}; \
	${INSTALL_DATA} build/freebsd*release/libtbb.so \
		${PREFIX}/lib/libtbb.so; \
	${MKDIR} ${PREFIX}/include/tbb/machine; \
	${FIND} include -type f -name '*.h' -exec \
		${INSTALL_DATA} \{\} ${PREFIX}/\{\} \;

.include <bsd.port.mk>
