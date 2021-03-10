# Created by: Ka Ho Ng <khng300@gmail.com>
# $FreeBSD$

PORTNAME=	rime-prelude
DISTVERSION=	g20210208
CATEGORIES=	chinese textproc

MAINTAINER=	khng300@gmail.com
COMMENT=	Essential files for building up your Rime configuration

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=		DOCS
OPTIONS_SUB=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	rime
GH_TAGNAME=	bc9ec4cad9fcaf3e300be9bbf2313104e75b5f25

NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	AUTHORS README.md

PLIST_FILES=	\
	share/rime-data/default.yaml \
	share/rime-data/key_bindings.yaml \
	share/rime-data/punctuation.yaml \
	share/rime-data/symbols.yaml

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/rime-data
	${INSTALL_DATA} ${WRKSRC}/default.yaml ${STAGEDIR}${PREFIX}/share/rime-data
	${INSTALL_DATA} ${WRKSRC}/key_bindings.yaml ${STAGEDIR}${PREFIX}/share/rime-data
	${INSTALL_DATA} ${WRKSRC}/punctuation.yaml ${STAGEDIR}${PREFIX}/share/rime-data
	${INSTALL_DATA} ${WRKSRC}/symbols.yaml ${STAGEDIR}${PREFIX}/share/rime-data

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/AUTHORS ${STAGEDIR}/${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
