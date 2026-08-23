PORTNAME=	cbmbasic
DISTVERSION=	20260403
CATEGORIES=	lang

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Portable version of Commodore 64 BASIC
WWW=		https://github.com/mist64/cbmbasic

# Check files cbmbasic.c, plugin.c and runtime.c
LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	mist64
GH_TAGNAME=	3b9e48d370241deded3bc3341ef7c8fc319bbb1f

PLIST_FILES=	bin/cbmbasic
PORTDOCS=	README.md
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cbmbasic ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
