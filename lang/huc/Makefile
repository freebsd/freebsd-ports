# Ports collection makefile for:	huc
# Date created:			1 December 2003
# Whom:				Frederic Cambus
#
# $FreeBSD$
#

PORTNAME=	huc
PORTVERSION=	3.20
PORTREVISION=	1
CATEGORIES=	lang emulators
MASTER_SITES=	http://www.zeograd.com/download/
DISTNAME=	huc_src_320
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PC Engine C compiler which can create ROMs (hucard) or CD images

WRKSRC=		${WRKDIR}/huc

USE_GMAKE=	yes

pre-build:
		@${RM} -rf ${WRKSRC}/include/CVS ${WRKSRC}/include/pce/CVS
		@${RM} -rf ${WRKSRC}/doc/CVS ${WRKSRC}/doc/huc/CVS \
		${WRKSRC}/doc/nes/CVS ${WRKSRC}/doc/pce/CVS

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/bin/huc ${PREFIX}/bin/huc
		${INSTALL_PROGRAM} ${WRKSRC}/bin/isolink ${PREFIX}/bin/isolink
		${INSTALL_PROGRAM} ${WRKSRC}/bin/nesasm ${PREFIX}/bin/nesasm
		${INSTALL_PROGRAM} ${WRKSRC}/bin/pceas ${PREFIX}/bin/pceas
		${INSTALL_PROGRAM} ${WRKSRC}/bin/pcxtool ${PREFIX}/bin/pcxtool
		@${MKDIR} ${PREFIX}/include/${PORTNAME}
		@${CP} -r ${WRKSRC}/include/ ${PREFIX}/include/${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
		@${MKDIR} ${DOCSDIR}
		@${CP} -r ${WRKSRC}/doc/ ${PREFIX}/share/doc/${PORTNAME}
.endif
	        @${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
