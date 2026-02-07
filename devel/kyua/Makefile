PORTNAME=	kyua
DISTVERSION=	0.14.1
PORTEPOCH=	3
CATEGORIES=	devel
MASTER_SITES=	https://github.com/freebsd/${PORTNAME}/releases/download/${DISTNAME}/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Testing framework for infrastructure software
WWW=		https://github.com/freebsd/kyua/

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	liblutok.so:devel/lutok

USES=		autoreconf libtool lua pkgconfig sqlite
USE_CXXSTD=	gnu++14

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
TEST_CONFIGURE_ENABLE=	atf

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
