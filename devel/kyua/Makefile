# $FreeBSD$

PORTNAME=	kyua
PORTVERSION=	0.11
PORTEPOCH=	2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/jmmv/kyua/releases/download/${PORTNAME}-${PORTVERSION}/ \
		LOCAL/jmmv

MAINTAINER=	jmmv@FreeBSD.org
COMMENT=	Testing framework for infrastructure software

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	liblutok.so:${PORTSDIR}/devel/lutok
LIB_DEPENDS+=	libsqlite3.so:${PORTSDIR}/databases/sqlite3
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFLICTS=	kyua-atf-compat-[0-9]* kyua-cli-[0-9]* kyua-testers-[0-9]*

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
TEST_BUILD_DEPENDS=	atf>=0.21:${PORTSDIR}/devel/atf
TEST_RUN_DEPENDS=	atf>=0.21:${PORTSDIR}/devel/atf

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
