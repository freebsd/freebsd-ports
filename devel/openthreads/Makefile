# New ports collection makefile for:	openthreads
# Date created:		16 October 2003
# Whom:			Ying-Chieh Chen <yinjieh@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	openthreads
PORTVERSION=	1.2d3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.csie.nctu.edu.tw/~yinjieh/
DISTNAME=	OpenThreads-v1.2dev3-osg0.9.6

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	A library which provides OO thread interface for C++ programmers

USE_GMAKE=	yes
USE_REINPLACE=	yes
MAKE_ENV=	PTHREAD_LIBS=${PTHREAD_LIBS}
INSTALLS_SHLIB=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}
MAKEFILE=	GNUmakefile

# opt = optimized ($OPTF added); debug = debug ($DBGF added); opt is default
ALL_TARGET=	opt

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,%%CXXFLAGS%%,${CXXFLAGS},g' \
	${WRKSRC}/Make/makedefs
	@${FIND} ${WRKSRC} -name '*.o' -delete
	@${FIND} ${WRKSRC} -name '*.so' -delete

.include <bsd.port.post.mk>
