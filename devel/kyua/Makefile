PORTNAME=	kyua
PORTVERSION=	0.13
PORTREVISION=	5
PORTEPOCH=	3
CATEGORIES=	devel
MASTER_SITES=	https://github.com/jmmv/kyua/releases/download/${PORTNAME}-${PORTVERSION}/ \
		LOCAL/jmmv

MAINTAINER=	jmmv@FreeBSD.org
COMMENT=	Testing framework for infrastructure software

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	liblutok.so:devel/lutok

USES=		lua pkgconfig sqlite

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir=${DOCSDIR} \
		--without-doxygen
MAKE_ARGS=	examplesdir=${EXAMPLESDIR} \
		pkgdatadir=${DATADIR}

CONFLICTS=	kyua-atf-compat-[0-9]* kyua-cli-[0-9]* kyua-testers-[0-9]*

SUB_FILES=	kyua.conf
_TESTS_USER=	tests
SUB_LIST=	TESTS_USER=${_TESTS_USER}
USERS=		${_TESTS_USER}
GROUPS=		tests

OPTIONS_DEFINE=		DOCS EXAMPLES TEST
OPTIONS_DEFAULT=	TEST
OPTIONS_SUB=		yes

DOCS_MAKE_ARGS_OFF=	doc_DATA=
EXAMPLES_MAKE_ARGS_OFF=	dist_examples_DATA=
TEST_BUILD_DEPENDS=	atf>=0.21:devel/atf
TEST_RUN_DEPENDS=	atf>=0.21:devel/atf
TEST_CONFIGURE_WITH=	atf

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/kyua
	${INSTALL_DATA} ${WRKDIR}/kyua.conf \
		${STAGEDIR}${PREFIX}/etc/kyua/kyua.conf.sample
	${INSTALL_DATA} ${WRKSRC}/examples/Kyuafile.top \
		${STAGEDIR}${PREFIX}/tests/Kyuafile

.include <bsd.port.mk>
