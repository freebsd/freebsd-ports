PORTNAME=	imaptest
PORTVERSION=	2026.10.23
CATEGORIES=	benchmarks mail sysutils

MAINTAINER=	ports@virtual-estates.net
COMMENT=	IMAP server compliance tester and benchmark
WWW=		https://github.com/dovecot/imaptest

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING.MIT

LIB_DEPENDS=	libdovecot.so:mail/dovecot24

USES=		autoreconf libtool
USE_GITHUB=	yes
GH_ACCOUNT=	dovecot
GH_TAGNAME=	ec2e118

CONFLICTS_BUILD=	dovecot-*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-dovecot=${LOCALBASE}/lib/dovecot

TEST_TARGET=	check
# dovecot24 records an opportunistically found valgrind.h in its config.h
TEST_ARGS=	${MAKE_ARGS} CPPFLAGS="-I${LOCALBASE}/include"

PLIST_FILES=	bin/imaptest
PORTDATA=	tests
PORTEXAMPLES=	*.conf

OPTIONS_DEFINE=	EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/src && ${COPYTREE_SHARE} tests ${STAGEDIR}${DATADIR} \
	    "! -path tests/broken*"

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/*.conf ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
