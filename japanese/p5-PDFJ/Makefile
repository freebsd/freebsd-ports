# New ports collection makefile for:	p5-PDFJ
# Date created:		Oct 22, 2002
# Whom:			kuriyama@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	PDFJ
PORTVERSION=	0.86
CATEGORIES=	japanese perl5
MASTER_SITES=	http://hp1.jonex.ne.jp/%7Enakajima.yasushi/archives/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	PDFJ module provides methods to generate Japanese PDF file

USE_ZIP=	YES
PERL_CONFIGURE=	YES
WRKSRC=		${WRKDIR}
EXTRACT_BEFORE_ARGS=	-qo -a

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/util/xpdfj.pl ${PREFIX}/bin
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/* ${EXAMPLESDIR}
	${MKDIR} ${DATADIR}/macro
	${INSTALL_DATA} ${WRKSRC}/macro/*.inc ${DATADIR}/macro

.include <bsd.port.post.mk>
