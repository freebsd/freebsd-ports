# Created by: Denise H. G. <darcsis@gmail.com>
# $FreeBSD$

PORTNAME=	tig
PORTVERSION=	2.5.3
CATEGORIES=	devel
MASTER_SITES=	https://github.com/jonas/tig/releases/download/${DISTNAME}/

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Text-mode interface for git

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	git:devel/git

USES=		iconv gmake ncurses readline:port
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${ICONV_CONFIGURE_BASE}
MAKE_ARGS=	V=1

INSTALL_TARGET=	install install-doc-man

# Tests fail when running as part of a non-interactive Poudriere
# build, but using script(1) seems to be a good enough workaround and
# allows them to run successfully anyway.
TEST_TARGET=	test
DO_MAKE_TEST=	/usr/bin/script -q /dev/null ${SETENV} ${TEST_ENV} ${GMAKE}

PLIST_FILES=	bin/tig \
		'@sample etc/tigrc.sample' \
		man/man1/tig.1.gz \
		man/man5/tigrc.5.gz \
		man/man7/tigmanual.7.gz

OPTIONS_DEFINE=	GIT

GIT_DESC=	Install devel/git as runtime dependency

GIT_RUN_DEPENDS=	git:devel/git
GIT_VARS_OFF=	PKGMESSAGE="${.CURDIR}/pkg-message-git"

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/tigrc ${STAGEDIR}${PREFIX}/etc/tigrc.sample
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/tig

.include <bsd.port.mk>
