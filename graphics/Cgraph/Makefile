# New ports collection makefile for:	cgraph
# Date created:		25 September 1998
# Whom:			Anton Berezin <tobez@plab.ku.dk>
#
# $FreeBSD$
#

PORTNAME=	Cgraph
PORTVERSION=	2.04
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.tobez.org/download/port-mirrors/graphics/Cgraph/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	A PostScript plotting library in C

WRKSRC=		${WRKDIR}/Cgraph/source
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:L}
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME:L}

USE_LDCONFIG=	yes

post-extract:
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../docs/cgraph.ps ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/../examples/minimal/CGminimal.c \
		${WRKSRC}/../examples/dash/dashlist.c \
		${WRKSRC}/../examples/marker/markerlist.c \
		${WRKSRC}/../examples/loglog/TFopt-lrLog.c \
		${WRKSRC}/../examples/loglog/TFampspect.dat ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
