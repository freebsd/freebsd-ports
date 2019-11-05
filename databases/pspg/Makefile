# $FreeBSD$

PORTNAME=	pspg
DISTVERSION=	2.5.3
CATEGORIES=	databases

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Tabular data pager designed to be used with psql

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf compiler:c11 gmake localbase ncurses pkgconfig \
		readline

USE_GITHUB=	yes
GH_ACCOUNT=	okbob
GNU_CONFIGURE=	yes

SUB_FILES=	pkg-message

PLIST_FILES=	bin/pspg
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS PGSQL
OPTIONS_DEFAULT=	PGSQL

PGSQL_DESC=	Work as PostgreSQL interactive client

PGSQL_USES=	pgsql
PGSQL_CONFIGURE_WITH=	postgresql=yes
PGSQL_VARS=	WANT_PGSQL=client

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pspg

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
