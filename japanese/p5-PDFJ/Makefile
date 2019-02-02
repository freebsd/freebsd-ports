# $FreeBSD$

PORTNAME=	PDFJ
PORTVERSION=	0.90
PORTREVISION=	3
CATEGORIES=	japanese perl5
MASTER_SITES=	http://hp1.jonex.ne.jp/%7Enakajima.yasushi/archives/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	PDFJ module provides methods to generate Japanese PDF file

USES=		perl5 shebangfix zip:infozip
USE_PERL5=	configure
EXTRACT_BEFORE_ARGS=	-qo -a
SHEBANG_FILES=	util/xpdfj.pl

NO_WRKSUBDIR=	yes

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/util/xpdfj.pl ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/* ${STAGEDIR}${EXAMPLESDIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/macro
	${INSTALL_DATA} ${WRKSRC}/macro/*.inc ${STAGEDIR}${DATADIR}/macro

.include <bsd.port.post.mk>
