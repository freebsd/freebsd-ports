PORTNAME=	kyua
DISTVERSION=	0.13
PORTREVISION=	9
PORTEPOCH=	3
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Testing framework for infrastructure software
WWW=		https://github.com/jmmv/kyua/

LICENSE=	BSD3CLAUSE

# Since 14.2 the test suite is based on execenv=jail feature of the latest Kyua,
# and tests(7) are expected to be aligned with Kyua version in the base,
# while the port is not going to be maintained to avoid double work.
DEPRECATED=	Consider using base version as tests(7) fail on 14.2 and later
EXPIRATION_DATE=	2026-04-30

LIB_DEPENDS=	liblutok.so:devel/lutok

USES=		autoreconf lua pkgconfig sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	freebsd
GH_TAGNAME=	c85354e
USE_CXXSTD=	gnu++11

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
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

# TODO: Get back to IGNORE after the alignment with the dependent ports
#.if ${OPSYS} == FreeBSD && ${OSREL:R} >= 14
#IGNORE=		kyua from base must be used for FreeBSD 14.x and newer
#.endif

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/kyua
	${INSTALL_DATA} ${WRKDIR}/kyua.conf \
		${STAGEDIR}${PREFIX}/etc/kyua/kyua.conf.sample
	${INSTALL_DATA} ${WRKSRC}/examples/Kyuafile.top \
		${STAGEDIR}${PREFIX}/tests/Kyuafile

.include <bsd.port.mk>
