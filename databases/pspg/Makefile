# $FreeBSD$

PORTNAME=	pspg
DISTVERSION=	0.7.5
CATEGORIES=	databases

MAINTAINER=	dg@syrec.org
COMMENT=	Tabular data pager designed to be used with psql

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf ncurses pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	okbob
GNU_CONFIGURE=	yes

CFLAGS+=	-D_WITH_GETLINE # enable the getline prototype
PLIST_FILES=	bin/pspg
PORTDOCS=	README.md

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pspg
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
