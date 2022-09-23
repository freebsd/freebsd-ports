PORTNAME=	jsmin
PORTVERSION=	20191031
CATEGORIES=	devel

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	The JavaScript Minifier
WWW=		https://crockford.com/javascript/jsmin.html

USE_GITHUB=	yes
GH_ACCOUNT=	douglascrockford
GH_PROJECT=	JSMin
GH_TAGNAME=	430bfe6

PLIST_FILES=	bin/jsmin
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${PORTNAME} ${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
