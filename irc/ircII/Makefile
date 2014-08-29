# Created by: torstenb
# $FreeBSD$

PORTNAME=	ircii
PORTVERSION=	20140824
CATEGORIES=	irc ipv6
MASTER_SITES=	http://ircii.warped.com/

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Small and high extensible IRC client

LICENSE=	BSD3CLAUSE

GNU_CONFIGURE=	yes
DATADIR=	${PREFIX}/share/irc
USES=		tar:bzip2

OPTIONS_DEFINE=	IRCBUG EMACS_KEYS OPENSSL
OPTIONS_DEFAULT=OPENSSL
OPTIONS_SUB=	yes

IRCBUG_DESC=	Install ircII bug-reporting script
EMACS_KEYS_DESC=Use emacs meta keys

EMACS_KEYS_CONFIGURE_WITH=	emacs-meta-keys
OPENSSL_USE=			OPENSSL=yes

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MOPENSSL}
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
.else
CONFIGURE_ARGS+=	--without-openssl
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^mandir =/s/@mandir@/$$(DESTDIR)&/' \
		-e '/^LDFLAGS =/s/$$/ -s/' \
		${WRKSRC}/Makefile.in

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/irc-${PORTVERSION}

.include <bsd.port.post.mk>
