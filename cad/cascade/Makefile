PORTNAME=	cascade
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	SF/rfcascade/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Simple tool to analyze noise and distortion of a RF system
WWW=		https://rfcascade.sourceforge.net/

GNU_CONFIGURE=	yes
USES=		groff
PORTDOCS=	ex1.gif index.html
PORTEXAMPLES=	README.examples ex1.cas ex1.gif ex1.out cascade-mode.el
PLIST_FILES=	bin/cascade share/man/man1/cascade.1.gz

CONFLICTS_INSTALL=	cascade-compiler

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cascade ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cascade.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* \
		${WRKSRC}/cascade-mode.el ${STAGEDIR}${EXAMPLESDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
