PORTNAME=	tractorgen
PORTVERSION=	0.31.7
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.vergenet.net/~conrad/software/tractorgen/dl/

MAINTAINER=	robin@15augustus.nl
COMMENT=	Generates ASCII tractors

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/tractorgen \
		man/man6/tractorgen.6.gz

PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=		DOCS

.include <bsd.port.options.mk>

post-install:
	${INSTALL_MAN} ${FILESDIR}/tractorgen.6 ${STAGEDIR}${PREFIX}/man/man6/tractorgen.6
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
