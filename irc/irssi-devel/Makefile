# $FreeBSD$

PORTNAME=	irssi
PORTVERSION=	20140530
CATEGORIES=	irc
MASTER_SITES=	http://mirror.irssi.org/snapshots/
PKGNAMESUFFIX=	-devel

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A modular IRC client with many features

LIB_DEPENDS=	libglib-2.0.so:${PORTSDIR}/devel/glib20

CONFLICTS=	irssi-0.8*

GNU_CONFIGURE=	yes
USES=		pkgconfig ncurses gmake
CONFIGURE_ARGS=	--with-ncurses=${NCURSESBASE}

OPTIONS_DEFINE=	PERL PROXY SOCKS IPV6 BOT SSL DOCS
SOCKS_DESC=	Socks proxy support
BOT_DESC=	Bot support
OPTIONS_DEFAULT=	PERL IPV6 SSL

WRKSRC=	${WRKDIR}/${PORTNAME}-0.8.17-svn

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
USE_OPENSSL=	yes
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

.if ${PORT_OPTIONS:MPERL}
USES+=		perl5
CONFIGURE_ARGS+=	--with-perl-lib=site
PLIST_SUB+=	WITH_PERL=""
.else
CONFIGURE_ARGS+=	--without-perl
PLIST_SUB+=	WITH_PERL="@comment "
.endif

.if ${PORT_OPTIONS:MPROXY}
CONFIGURE_ARGS+=	--with-proxy
PLIST_SUB+=	WITH_PROXY=""
.else
PLIST_SUB+=	WITH_PROXY="@comment "
.endif

.if ${PORT_OPTIONS:MSOCKS}
CONFIGURE_ARGS+=	--with-socks
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
CATEGORIES+=	ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${PORT_OPTIONS:MBOT}
CONFIGURE_ARGS+=	--with-bot
PLIST_SUB+=	WITH_BOT=""
.else
CONFIGURE_ARGS+=	--without-bot
PLIST_SUB+=	WITH_BOT="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' -e 's|/etc|${PREFIX}&|' \
		${WRKSRC}/docs/irssi.1
.if empty(PORT_OPTIONS:MDOCS)
	${REINPLACE_CMD} -e \
		'/^install-data-am:/ s|install-docDATA||' \
		${WRKSRC}/docs/Makefile.in
.endif

post-configure:
	@${MV} ${WRKSRC}/irssi.conf ${WRKSRC}/irssi.conf.sample

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/irssi/modules
.if ${PORT_OPTIONS:MPERL}
	@${FIND} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto -name .packlist -exec ${SED} -i '' 's|^${STAGEDIR}||' '{}' \;
.endif

.include <bsd.port.mk>
