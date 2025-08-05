PORTNAME=	kanbanapp
PORTVERSION=	1.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Simple offline Kanban-like program written with Qt
WWW=		https://github.com/noedigcode/Kanbanapp

#LICENSE=	https://github.com/noedigcode/Kanbanapp/issues/2

USES=		gmake qmake qt:5
USE_QT=		buildtools:build core gui widgets
USE_GITHUB=	yes
GH_ACCOUNT=	noedigcode
GH_PROJECT=	Kanbanapp

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	changelog.txt readme.md

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
