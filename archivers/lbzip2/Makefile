PORTNAME=	lbzip2
PORTVERSION=	2.5
CATEGORIES=	archivers
MASTER_SITES=	${WWW}/releases/download/v${PORTVERSION}/ \
		LOCAL/danfe

LICENSE=	GPLv3+

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Multi-threaded bzip2/bunzip2 filter
WWW=		https://github.com/kjn/lbzip2

USES=		tar:bzip2
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/lbunzip2 bin/lbzcat bin/lbzip2 \
		share/man/man1/lbunzip2.1.gz \
		share/man/man1/lbzcat.1.gz \
		share/man/man1/lbzip2.1.gz

PORTDOCS=	AUTHORS ChangeLog NEWS README THANKS

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
