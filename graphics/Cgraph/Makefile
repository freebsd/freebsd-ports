# New ports collection makefile for:	cgraph
# Date created:		25 September 1998
# Whom:			Anton Berezin <tobez@plab.ku.dk>
#
# $FreeBSD$
#

PORTNAME=	Cgraph
PORTVERSION=	2.04
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.tobez.org/download/port-mirrors/graphics/Cgraph/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	A PostScript plotting library in C

WRKSRC=		${WRKDIR}/Cgraph/source

INSTALLS_SHLIB=	yes

post-extract:
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/cgraph
	@${INSTALL_DATA} ${WRKSRC}/../docs/cgraph.ps ${PREFIX}/share/doc/cgraph
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${PREFIX}/share/examples/cgraph
	@${INSTALL_DATA} ${WRKSRC}/../examples/minimal/CGminimal.c ${PREFIX}/share/examples/cgraph
	@${INSTALL_DATA} ${WRKSRC}/../examples/dash/dashlist.c ${PREFIX}/share/examples/cgraph
	@${INSTALL_DATA} ${WRKSRC}/../examples/marker/markerlist.c ${PREFIX}/share/examples/cgraph
	@${INSTALL_DATA} ${WRKSRC}/../examples/loglog/TFopt-lrLog.c ${PREFIX}/share/examples/cgraph
	@${INSTALL_DATA} ${WRKSRC}/../examples/loglog/TFampspect.dat ${PREFIX}/share/examples/cgraph
.endif

.include <bsd.port.mk>
