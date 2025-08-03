PORTNAME=	pspg
DISTVERSION=	5.8.12
CATEGORIES=	databases

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Tabular data pager designed to be used with psql
WWW=		https://github.com/okbob/pspg

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf compiler:c11 gmake localbase ncurses:port pkgconfig \
		readline

USE_GITHUB=	yes
GH_ACCOUNT=	okbob

GNU_CONFIGURE=	yes

SUB_FILES=	pkg-message

PLIST_FILES=	bin/pspg share/man/man1/pspg.1.gz
PORTDOCS=	README.md

OPTIONS_DEFINE=		DOCS INOTIFY PGSQL
OPTIONS_DEFAULT=	INOTIFY PGSQL

INOTIFY_DESC=	Use inotify instead of polling
PGSQL_DESC=	Work as PostgreSQL interactive client

INOTIFY_LIB_DEPENDS=	libinotify.so:devel/libinotify
# configure script doesn't understand --with-inotify
INOTIFY_CONFIGURE_OFF=	--without-inotify
INOTIFY_LDFLAGS=	-linotify

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_WITH=	postgresql=yes
PGSQL_VARS=		WANT_PGSQL=client

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pspg
	${INSTALL_MAN} ${WRKSRC}/pspg.1 ${STAGEDIR}${PREFIX}/share/man/man1/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
