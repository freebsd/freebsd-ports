# New ports collection makefile for:	e00compr
# Date created:				May 04 , 2008
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	e00compr
PORTVERSION=	1.0.1
CATEGORIES=	devel
MASTER_SITES=	http://avce00.maptools.org/dl/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	A Library to Read/Write Compressed E00 Files

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
PLIST_FILES=	bin/e00conv include/e00compr.h \
		lib/e00compr.a
PORTDOCS=	e00compr.html

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/e00conv ${PREFIX}/bin/e00conv
	${INSTALL_DATA} ${WRKSRC}/e00compr.h ${PREFIX}/include/e00compr.h
	${INSTALL_DATA} ${WRKSRC}/e00compr.a ${PREFIX}/lib/e00compr.a

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/e00compr.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
