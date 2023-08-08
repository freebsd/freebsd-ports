PORTNAME=	l2p
PORTVERSION=	1.1.1
PORTREVISION=	5
CATEGORIES=	graphics print perl5
MASTER_SITES=	http://static.redsymbol.net/software/l2p/dist/ \
		http://nivit.altervista.org/FreeBSD/ports/distfiles/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Create PNG images from LaTeX math expressions
WWW=		http://www.redsymbol.net/software/l2p/

NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/l2p
PORTDOCS=	l2p.txt l2p.html

SHEBANG_FILES=	${WRKSRC}/${PORTNAME}

USE_PERL5=	run
USE_TEX=	latex dvipsk
USES=		magick:6,run perl5 shebangfix tex zip

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
