# New ports collection makefile for:	clustalw
# Date created:				6 July 2000
# Whom:					dbader@eece.unm.edu
#
# $FreeBSD$
#

PORTNAME=	clustalw
PORTVERSION=	1.81
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp-igbmc.u-strasbg.fr/pub/ClustalW/
DISTNAME=	clustalw1.81.UNIX

MAINTAINER=	dbader@eece.unm.edu

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}

do-build:
		cd ${WRKSRC} ; ${MAKE} -f makefile

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/clustalw ${PREFIX}/bin
		${MKDIR} ${PREFIX}/share/${PORTNAME}
		${INSTALL_DATA} ${WRKSRC}/clustalw_help ${PREFIX}/share/${PORTNAME}

.include <bsd.port.mk>
