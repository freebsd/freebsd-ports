PORTNAME=	silentbob
PORTVERSION=	3.2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}3/

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Yet another sourcecode indexing tool
WWW=		https://silentbob.sourceforge.net/

LICENSE=	GPLv2

PLIST_FILES=	bin/silentbob
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-build:
	@(cd ${BUILD_WRKSRC} && \
		${CXX} ${CXXFLAGS} src/*.cpp -Iinclude -o silentbob)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/silentbob ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
