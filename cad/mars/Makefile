# ex:ts=8
# New ports collection makefile for:    MaRS
# Version required:     2.1
# Date created:         Mon Nov 18, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id: Makefile,v 1.5 1997/02/04 11:32:02 obrien Exp $
#

DISTNAME=	MaRS-2.1
PKGNAME=	mars-2.1
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.cs.umd.edu/pub/sdag/MaRS/
.if !defined(NOPORTDOCS)
DISTFILES=	MaRS-2.1.tar.gz MaRS-2-doc.tar.gz
.endif

MAINTAINER=     obrien@FreeBSD.org

NO_WRKSUBDIR=	yes
EXTRACT_ONLY=	${DISTNAME}.tar.gz
.if defined(HAVE_MOTIF) && !defined(PACKAGE_BUILDING)
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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/mars
	@chmod a+rx ${PREFIX}/share/doc/mars
	@(cd ${PREFIX}/share/doc ; \
		${EXTRACT_CMD} xfpz /${DISTDIR}/MaRS-2-doc.tar.gz ; \
		[ -d mars ] && ${RM} -rf mars; \
		/bin/mv doc mars )
.endif

.include <bsd.port.mk>
