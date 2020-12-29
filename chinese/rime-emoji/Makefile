# Created by: Ka Ho Ng <khng300@gmail.com>
# $FreeBSD$

PORTNAME=	rime-emoji
DISTVERSION=	g20201113
CATEGORIES=	chinese textproc

MAINTAINER=	khng300@gmail.com
COMMENT=	Rime emoji suggestions support

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	rime
GH_TAGNAME=	35c9632c34ea29e6d9ed80ff350c05f3d706fdc6

NO_ARCH=	yes
NO_BUILD=	yes

PORTDOCS=	AUTHORS README.md

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/rime-data
	${INSTALL_DATA} ${WRKSRC}/emoji_suggestion.yaml ${STAGEDIR}${PREFIX}/share/rime-data
	(cd ${WRKSRC} && ${COPYTREE_SHARE} opencc ${STAGEDIR}${PREFIX}/share/rime-data)

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/AUTHORS ${STAGEDIR}/${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
