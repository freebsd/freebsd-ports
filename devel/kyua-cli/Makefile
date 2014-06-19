# Created by: Alan Somers <asomers@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kyua-cli
PORTVERSION=	0.8
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PROJECTHOST=	kyua

MAINTAINER=	jmmv@FreeBSD.org
COMMENT=	Kyua (automated testing framework) - Command line interface

LICENSE=	BSD

LIB_DEPENDS=	liblutok.so.3:${PORTSDIR}/devel/lutok
LIB_DEPENDS+=	sqlite3:${PORTSDIR}/databases/sqlite3
BUILD_DEPENDS=	kyua-testers>=0.2:${PORTSDIR}/devel/kyua-testers
RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USES=		pkgconfig

TESTS_USER=	tests
USERS=		${TESTS_USER}
SUB_FILES=	kyua.conf
SUB_LIST=	TESTS_USER=${TESTS_USER}

OPTIONS_DEFINE=	DOCS EXAMPLES TEST
OPTIONS_DEFAULT=TEST

OPTIONS_SUB=		yes
TEST_CONFIGURE_WITH=	atf
TEST_BUILD_DEPENDS=	atf>=0.20:${PORTSDIR}/devel/atf
TEST_RUN_DEPENDS=	atf>=0.20:${PORTSDIR}/devel/atf

.include <bsd.port.options.mk>

CONFIGURE_ARGS+=	--without-doxygen
CONFIGURE_ARGS+=	--docdir=${DOCSDIR}
MAKE_FLAGS+=	examplesdir=${EXAMPLESDIR}
MAKE_FLAGS+=	pkgdatadir=${DATADIR}

.if ! ${PORT_OPTIONS:MDOCS}
MAKE_FLAGS+=	doc_DATA=
.endif
.if ! ${PORT_OPTIONS:MEXAMPLES}
MAKE_FLAGS+=	dist_examples_DATA=
.endif

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/kyua/
	${INSTALL_DATA} ${WRKDIR}/kyua.conf ${STAGEDIR}${PREFIX}/etc/kyua/
	${INSTALL_DATA} ${WRKSRC}/examples/Kyuafile.top \
		${STAGEDIR}${PREFIX}/tests/Kyuafile

.include <bsd.port.mk>
