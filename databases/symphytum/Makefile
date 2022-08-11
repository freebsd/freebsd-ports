PORTNAME=	symphytum
PORTVERSION=	2.6
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Personal, user-friendly database software

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		qmake qt:5
USE_QT=		buildtools_build \
		core gui network printsupport sql svg widgets
USE_GITHUB=	yes
GH_ACCOUNT=	giowck

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	AUTHORS CHANGELOG.md

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
