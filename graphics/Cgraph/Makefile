# New ports collection makefile for:	cgraph
# Version required:	2.04
# Date created:		25 September 1998
# Whom:			Anton Berezin <tobez@plab.ku.dk>
#
# $FreeBSD$
#

DISTNAME=	Cgraph2.04
PKGNAME=	Cgraph-2.04
CATEGORIES=	graphics
MASTER_SITES=	http://totoro.berkeley.edu/software/

MAINTAINER=	tobez@plab.ku.dk

WRKSRC=		${WRKDIR}/Cgraph/source

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
	@${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
