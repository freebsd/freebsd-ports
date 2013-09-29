# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jsmin
PORTVERSION=	20130329
CATEGORIES=	devel

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	The JavaScript Minifier

USE_GITHUB=	yes
GH_ACCOUNT=	douglascrockford
GH_PROJECT=	JSMin
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	1bf6ce5

PLIST_FILES=	bin/jsmin
PORTDOCS=	README

.include <bsd.port.options.mk>

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${PORTNAME} ${PORTNAME}.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
