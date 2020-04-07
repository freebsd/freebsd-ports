# $FreeBSD$

PORTNAME=	pspg
DISTVERSION=	3.0.0
CATEGORIES=	databases

# https://github.com/okbob/pspg/issues/128
PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	96330321c187e6ee199ff0c41c65002e17c25f33.patch:-p1

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

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
