# Created by: Alan Somers <asomers@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kyua
PORTVERSION=	0.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PROJECTHOST=	kyua
DISTNAME=	kyua-cli-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	Kyua (automated testing framework) - Command line interface

LICENSE=	BSD

LIB_DEPENDS=	liblutok.so.2:${PORTSDIR}/devel/lutok
LIB_DEPENDS+=	sqlite3:${PORTSDIR}/databases/sqlite3
BUILD_DEPENDS=	${LOCALBASE}/libexec/kyua-atf-tester:${PORTSDIR}/devel/kyua-testers
RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USES=		pkgconfig

OPTIONS_DEFINE=	DOCS EXAMPLES
NO_STAGE=	yes
.include <bsd.port.options.mk>

CONFIGURE_ARGS+=	--without-doxygen
CONFIGURE_ARGS+=	--docdir=${DOCSDIR}
# TODO: install the tests, once FreeBSD has a system for ports to install tests
CONFIGURE_ARGS+=	--without-atf
MAKE_FLAGS+=	pkgdatadir=${DATADIR}

.if ! ${PORT_OPTIONS:MDOCS}
MAKE_FLAGS+=	doc_DATA=
.endif
.if ! ${PORT_OPTIONS:MEXAMPLES}
MAKE_FLAGS+=	dist_examples_DATA=
.endif
PLIST_FILES=	bin/kyua

PORTDATA=	misc store examples
PORTDOCS=	AUTHORS COPYING NEWS README
MAN1=	kyua-about.1 kyua-config.1 kyua-db-exec.1 kyua-db-migrate.1
MAN1+=	kyua-debug.1 kyua-help.1 kyua-list.1 kyua-report-html.1
MAN1+=	kyua-report.1 kyua-test.1 kyua.1
MAN5=	kyua.conf.5 kyuafile.5
MAN7=	kyua-build-root.7 kyua-test-filters.7

.include <bsd.port.mk>
