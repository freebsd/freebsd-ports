# New ports collection makefile for:    sim
# Version required:     2.3
# Date created:         7 November 1997
# Whom:			jraynard
#
# $FreeBSD$
#

DISTNAME=	sim_2.3
PKGNAME=	sim-2.3
CATEGORIES=	emulators
MASTER_SITES=	ftp://minnie.cs.adfa.oz.au/pub/PDP-11/Sims/Supnik_2.3/sources/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}.update1.tar.gz

MAINTAINER=	jraynard@FreeBSD.org

RESTRICTED=	"Non-commercial use only"

NO_WRKSUBDIR=	yes

post-configure:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/i1401 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/nova ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/pdp1 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/pdp4 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/pdp7 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/pdp8 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/pdp9 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/pdp11 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/pdp15 ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/sim && ${INSTALL_DATA} ${WRKDIR}/simh_doc.txt \
		${PREFIX}/share/doc/sim
.endif

.include <bsd.port.mk>
