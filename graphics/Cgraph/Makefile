# New ports collection makefile for:	cgraph
# Version required:	2.04
# Date created:		25 September 1998
# Whom:			Anton Berezin <tobez@plab.ku.dk>
#
# $Id$
#

DISTNAME=	Cgraph2.04
PKGNAME=	Cgraph-2.04
CATEGORIES=	graphics
MASTER_SITES=	ftp://pinoko.berkeley.edu/pub/software/

MAINTAINER=	tobez@plab.ku.dk

WRKSRC=		${WRKDIR}/Cgraph/source

.include <bsd.port.pre.mk>

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
.if ${PORTOBJFORMAT} == "aout"
	@${LN} -sf libcgraph.so.2.4 ${PREFIX}/lib/libcgraph.so
.endif
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.post.mk>
