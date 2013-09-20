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

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${PORTNAME} ${PORTNAME}.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
