PORTNAME=	kyua
DISTVERSION=	0.13
PORTREVISION=	7
PORTEPOCH=	3
CATEGORIES=	devel

MAINTAINER=	jmmv@FreeBSD.org
COMMENT=	Testing framework for infrastructure software
WWW=		https://github.com/jmmv/kyua/

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	liblutok.so:devel/lutok

USES=		autoreconf lua pkgconfig sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	freebsd
GH_TAGNAME=	84c8ec8
USE_CXXSTD=	gnu++11

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir=${DOCSDIR} \
		--without-doxygen
MAKE_ARGS=	examplesdir=${EXAMPLESDIR} \
		pkgdatadir=${DATADIR}

CONFLICTS=	kyua-atf-compat kyua-cli kyua-testers

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
