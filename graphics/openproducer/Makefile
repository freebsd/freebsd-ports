# New ports collection makefile for:	openproducer
# Date created:		22 July 2003
# Whom:			Ying-Chieh Chen <yinjieh@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	openproducer
PORTVERSION=	0.8.4.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.andesengineering.com/Producer/Download/
DISTNAME=	Producer-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	A cross-platform C++/OpenGL library focused on camera control

BUILD_DEPENDS=	${LOCALBASE}/lib/libOpenThreads.so:${PORTSDIR}/devel/openthreads

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_MESA=	yes
USE_GMAKE=	yes
MAKE_ENV=	PTHREAD_LIBS=${PTHREAD_LIBS}
ONLY_FOR_ARCHS=         i386

WRKSRC=		${WRKDIR}/Producer
MAKEFILE=	GNUmakefile

# opt = optimized ($OPTF added); debug = debug ($DBGF added); opt is default
ALL_TARGET=	opt

post-patch:
	@${REINPLACE_CMD} -e 's,%%CXXFLAGS%%,${CXXFLAGS},g' \
	${WRKSRC}/Make/makedefs

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -r ${WRKSRC}/doc/ ${DOCSDIR}
.endif

.include <bsd.port.mk>
