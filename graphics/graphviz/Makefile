# New ports collection makefile for:    graphviz
# Version required:     1.5
# Date created:         03 Feb 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=       gviz15
PKGNAME=	graphviz-1.5
CATEGORIES=	graphics tk82
MASTER_SITES=	http://www.research.att.com/sw/tools/graphviz/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82

FETCH_ARGS=	-b
WRKSRC=		${WRKDIR}/gv1.5
MAKEFILE=	makefile
MAN1=		dot.1 dotty.1 lefty.1 neato.1
MANN=		tcldot.n

DOCDIR=		${PREFIX}/share/doc/graphviz

post-extract:
	@find ${WRKSRC} -name *.o -delete

post-install:
	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/*.htm* ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.ps ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCDIR}
	@${GZIP_CMD} ${DOCDIR}/*.ps

.include <bsd.port.mk>
