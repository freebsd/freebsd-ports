# New ports collection makefile for:	Psi88
# Date created:		1998-11-11
# Whom:			Ryo MIYAMOTO
#
# $FreeBSD$
#

PORTNAME=	psi88
PORTVERSION=	1.0
CATEGORIES=	biology
MASTER_SITES=	http://www.ccl.net/cca/software/SOURCES/FORTRAN/psi88/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	rmiya@cc.hirosaki-u.ac.jp
COMMENT=	Plotting wavefunctions (molecular orbitals) in 3D

pre-patch:
	${MV} ${WRKSRC}/src/makefile ${WRKSRC}/src/Makefile

pre-build:
	${CP} ${FILESDIR}/Makefile.top ${WRKSRC}/Makefile

post-install:
	${LN} -s ${PREFIX}/bin/PSI2PS ${PREFIX}/bin/PSI2
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/unix/preplot ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/unix/rpsi1 ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/unix/rpsi2 ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/unix/rpsicon ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/psi88
	${MKDIR} ${PREFIX}/share/doc/psi88/examples
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README ${PREFIX}/share/doc/psi88
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/psi88.doc ${PREFIX}/share/doc/psi88
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/examples/* ${PREFIX}/share/doc/psi88/examples
.endif

.include <bsd.port.mk>
