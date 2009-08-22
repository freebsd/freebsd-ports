# New ports collection makefile for:	avida
# Date created:		17 April 2002
# Whom:			Jeremy <karlj000@unbc.ca>
#
# $FreeBSD$
#

PORTNAME=	avida
PORTVERSION=	2.8.1
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-stable/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Avida is an auto-adaptive genetic system designed for ALife research

USE_CMAKE=	yes
USE_GCC=	4.2+

WRKSRC=		${WRKDIR}/${PORTNAME}-src-${PORTVERSION}

PORTDOCS=	*

post-extract:
	@${RM} -f ${WRKSRC}/documentation/.[D_]*

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/work/avida ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/work/avida-viewer ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/work/*.cfg ${WRKSRC}/work/*.org ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/documentation && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.mk>
