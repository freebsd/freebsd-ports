PORTNAME=	tig
DISTVERSION=	2.5.12
CATEGORIES=	devel
MASTER_SITES=	https://github.com/jonas/tig/releases/download/${DISTNAME}/

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Text-mode interface for git
WWW=		https://jonas.github.io/tig/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	git:devel/git

USES=		gmake iconv ncurses pkgconfig readline
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${ICONV_CONFIGURE_BASE}
MAKE_ARGS=	V=1

INSTALL_TARGET=	install install-doc-man

# Tests fail when running as part of a non-interactive Poudriere
# build, but using script(1) seems to be a good enough workaround and
# allows them to run successfully anyway.
TEST_TARGET=	test-address-sanitizer
DO_MAKE_TEST=	script -q /dev/null ${SETENV} ${TEST_ENV} ${GMAKE}

PLIST_FILES=	bin/tig \
		'@sample etc/tigrc.sample' \
		share/man/man1/tig.1.gz \
		share/man/man5/tigrc.5.gz \
		share/man/man7/tigmanual.7.gz

OPTIONS_DEFINE=	GIT PCRE

GIT_DESC=	Install devel/git as runtime dependency

GIT_RUN_DEPENDS=	git:devel/git
GIT_VARS_OFF=		PKGMESSAGE="${.CURDIR}/pkg-message-git"
PCRE_LIB_DEPENDS=	libpcre2-posix.so:devel/pcre2
PCRE_CONFIGURE_WITH=	pcre

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/tigrc ${STAGEDIR}${PREFIX}/etc/tigrc.sample
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/tig

.include <bsd.port.mk>
