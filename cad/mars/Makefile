# ex:ts=8
# New ports collection makefile for:    MaRS
# Version required:     2.1
# Date created:         Mon Nov 18, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id: Makefile,v 1.1.1.1 1996/11/25 01:07:50 obrien Exp $
#

DISTNAME=	MaRS-2.1
CATEGORIES=	cad
DISTSITE=	ftp://ftp.cs.umd.edu/pub/sdag/MaRS/
MASTER_SITES=	${DISTSITE}

MAINTAINER=     obrien@cs.ucdavis.edu

NO_WRKSUBDIR=	yes
.if defined(HAVE_MOTIF) && defined(FORCE_MOTIF)
MAKEFILE=       Makefile.XMotif
.elif defined(WITH_X) && (${WITH_X} == NO || ${WITH_X} == no)
MAKEFILE=	Makefile.NoX
.else
MAKEFILE=	Makefile.SimpleX
.endif
ALL_TARGET=	depend mars
MAN1=		mars.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mars ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/mars.1 ${PREFIX}/man/man1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/mars  \
		&& chmod a+rx ${PREFIX}/share/doc/mars
	@[ -f ${DISTDIR}/MaRS-2-doc.tar.gz ] || \
	${FETCH_CMD} -o /${DISTDIR}/MaRS-2-doc.tar.gz  \
		${DISTSITE}MaRS-2-doc.tar.gz
	@(cd ${PREFIX}/share/doc ; \
		${EXTRACT_CMD} xfpz /${DISTDIR}/MaRS-2-doc.tar.gz ; \
		[ -d mars ] && ${RM} -rf mars; \
		/bin/mv doc mars )
.endif

.include <bsd.port.mk>
