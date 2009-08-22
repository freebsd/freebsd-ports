# New ports collection makefile for:	tokamak
# Date created:		24 Jun 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tokamak
PORTVERSION=	1.0.5a
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}p/Tokamak%20Physics%20Engine/Tokamak%20${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	High performance real-time physics library

USE_ZIP=	yes
USE_GMAKE=	yes
USE_DOS2UNIX=	*

MAKEFILE=	tokamak.make
ALL_TARGET=

WRKSRC=		${WRKDIR}/tokamak_release
BUILD_WRKSRC=	${WRKSRC}/build/gnu

PORTDOCS=	*

.include <bsd.port.pre.mk>

.if !defined(WITH_DEBUG)
MAKE_ENV+=	CPPFLAGS=-DNDEBUG
.endif

post-extract:
	@cd ${WRKSRC} && ${UNZIP_CMD} -q tokamak-premake.zip

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/include/tokamak.h

do-install:
	${MKDIR} ${PREFIX}/include/math/
	${INSTALL_DATA} ${WRKSRC}/include/tokamak.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/math/*.h ${PREFIX}/include/math/
	${INSTALL_DATA} ${WRKSRC}/lib/libtokamak_m.a ${PREFIX}/lib/

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/license.txt ${WRKSRC}/readme.txt ${DOCSDIR}
	cd ${WRKSRC}/documentation && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
