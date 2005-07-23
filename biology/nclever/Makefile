# New ports collection makefile for:	nclever
# Date created:				17 August 2001
# Whom:			 		Tony Maher
#
# $FreeBSD$
#

PORTNAME=	nclever
PORTVERSION=	4.0
CATEGORIES=	biology
MASTER_SITES=	ftp://megasun.bch.umontreal.ca/pub/nclever/
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tonym@biolateral.com.au
COMMENT=	NClever is a character-based version of NCBI's Entrez program

BUILD_DEPENDS=	${LOCALBASE}/lib/ncbi/libncbi.a:${PORTSDIR}/biology/ncbi-toolkit

BROKEN=		Unfetchable
DEPRECATED=	"${BROKEN}"
EXPIRATION_DATE=2005-09-22

do-install:
	@${MKDIR} ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/nclever ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/nclever_manual.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/nclever.citation ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/sample_script1.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/sample_script2.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
