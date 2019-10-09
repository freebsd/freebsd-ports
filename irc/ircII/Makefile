# Created by: torstenb
# $FreeBSD$

PORTNAME=	ircii
PORTVERSION=	20190117
CATEGORIES=	irc
MASTER_SITES=	http://ircii.warped.com/

MAINTAINER=	andrew@tao11.riddles.org.uk
COMMENT=	Small and high extensible IRC client

LICENSE=	BSD3CLAUSE

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-warnings
DATADIR=	${PREFIX}/share/irc
USES=		iconv ncurses tar:bzip2

OPTIONS_DEFINE=	EMACS_KEYS HELP IRCBUG OPENSSL SCRIPTS
OPTIONS_DEFAULT=EMACS_KEYS HELP OPENSSL SCRIPTS
OPTIONS_SUB=	yes

HELP_DESC=	Install ircII help files
EMACS_KEYS_DESC=Use emacs meta keys
IRCBUG_DESC=	Install ircII bug-reporting script
SCRIPTS_DESC=	Install ircII script collection

EMACS_KEYS_CONFIGURE_WITH=	emacs-meta-keys
OPENSSL_USES=			ssl
OPENSSL_CONFIGURE_WITH=		openssl=${OPENSSLBASE}
OPENSSL_LDFLAGS=		-L${OPENSSLLIB}

.include <bsd.port.pre.mk>

# The ordering is very specific. This must come after pre.mk or
# ircII won't link against libssl from ports
CPPFLAGS+=	-I${ICONV_PREFIX}/include
LDFLAGS+=	-L${ICONV_PREFIX}/lib

post-patch:
	@${REINPLACE_CMD} -e '/^mandir =/s/@mandir@/$${DESTDIR}&/' \
		-e '/^LDFLAGS =/s/$$/ ${STRIP} ${ICONV_LIB}/' \
		-e '/^INCLUDES =/s|$$| -I${ICONV_PREFIX}/include -DHAVE_ICONV_OPEN|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|PREFIX/|${PREFIX}/|' ${WRKSRC}/doc/ircII.1

post-install:
	${MV} -f ${STAGEDIR}${PREFIX}/bin/irc-${PORTVERSION} ${STAGEDIR}${PREFIX}/bin/irc

.include <bsd.port.post.mk>
