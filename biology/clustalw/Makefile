# New ports collection makefile for:	clustalw
# Date created:				6 July 2000
# Whom:					dbader@eece.unm.edu
#
# $FreeBSD$
#

PORTNAME=	clustalw
PORTVERSION=	2.0
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.ebi.ac.uk/pub/software/clustalw2/
DISTNAME=	${PORTNAME}-linux-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CLUSTAL W Multiple Sequence Alignment Program

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}

ALL_TARGET=	# empty

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/clustalw2 ${PREFIX}/bin
	${LN} -sf clustalw2 ${PREFIX}/bin/clustalw
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/clustalw_help ${DATADIR}

.include <bsd.port.mk>
