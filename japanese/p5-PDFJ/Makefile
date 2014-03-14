# $FreeBSD$

PORTNAME=	PDFJ
PORTVERSION=	0.90
PORTREVISION=	2
CATEGORIES=	japanese perl5
MASTER_SITES=	http://hp1.jonex.ne.jp/%7Enakajima.yasushi/archives/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	PDFJ module provides methods to generate Japanese PDF file

USES=		perl5 zip:infozip
USE_PERL5=	configure
WRKSRC=		${WRKDIR}
EXTRACT_BEFORE_ARGS=	-qo -a

NO_STAGE=	yes
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
