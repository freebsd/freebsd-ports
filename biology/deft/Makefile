# New ports collection makefile for:  DeFT
# Date created:  1999-01-11
# Whom:	 Ryo MIYAMOTO <rmiya@cc.hirosaki-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	deft
PORTVERSION=	2.2
CATEGORIES=	biology
MASTER_SITES=	ftp://theory.chem.uottawa.ca/pub/
DISTNAME=	DeFT_${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	rmiya@cc.hirosaki-u.ac.jp

WRKSRC=		${WRKDIR}/${DISTNAME}/source

post-configure:
	${CP} ${FILESDIR}/Makefile.deft ${WRKSRC}/Makefile

pre-install:
	${RM} -rf ${PREFIX}/share/doc/DeFT
	${MKDIR} ${PREFIX}/share/doc/DeFT
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/DeFT/examples
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/DeFT.exec ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/examples/DeFT ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/bases ${PREFIX}/share/doc/DeFT/

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README_Liability ${PREFIX}/share/doc/DeFT/
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/input.*  ${PREFIX}/share/doc/DeFT/
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/install.*  ${PREFIX}/share/doc/DeFT/
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/examples/*  ${PREFIX}/share/doc/DeFT/examples/
	${RM} -f ${PREFIX}/share/doc/DeFT/examples/DeFT*
.endif

.include <bsd.port.mk>
