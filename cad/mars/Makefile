# Ports collection makefile for:  MaRS
# Date created:			  Mon Nov 18, 1996
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	mars
PORTVERSION=	2.1
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.cs.umd.edu/pub/sdag/MaRS/
DISTNAME=	MaRS-${PORTVERSION}
.if !defined(NOPORTDOCS)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} MaRS-2-doc${EXTRACT_SUFX}
.endif

MAINTAINER=	ports@FreeBSD.org

NO_WRKSUBDIR=	yes
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.if defined(WITHOUT_X11)
MAKEFILE=	Makefile.NoX
.else
USE_MOTIF=	yes
MAKEFILE=	Makefile.XMotif
.endif
ALL_TARGET=	depend mars
MAN1=		mars.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mars ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/mars.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/mars
	@${CHMOD} a+rx ${PREFIX}/share/doc/mars
	@(cd ${PREFIX}/share/doc ; \
		${TAR} xfpz /${DISTDIR}/MaRS-2-doc${EXTRACT_SUFX} ; \
		[ -d mars ] && ${RM} -rf mars; \
		${MV} doc mars )
.endif

.include <bsd.port.mk>
