# New ports collection makefile for:	clustalw
# Date created:				6 July 2000
# Whom:					dbader@eece.unm.edu
#
# $FreeBSD$
#

PORTNAME=	clustalw
PORTVERSION=	1.83
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp-igbmc.u-strasbg.fr/pub/ClustalW/
DISTNAME=	${PORTNAME}${PORTVERSION}.UNIX

MAINTAINER=	dbader@eece.unm.edu
COMMENT=	CLUSTAL W Multiple Sequence Alignment Program

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}

MAKEFILE=	makefile
ALL_TARGET=	# empty

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/clustalw ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/clustalw_help ${DATADIR}

.include <bsd.port.mk>
