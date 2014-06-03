# $FreeBSD$

PORTNAME=	irssi
PORTVERSION=	0.8.16
PORTREVISION=	1
CATEGORIES?=	irc
MASTER_SITES=	http://mirror.irssi.org/

MAINTAINER?=	vanilla@FreeBSD.org
COMMENT?=	Modular IRC client with many features

LIB_DEPENDS=	libglib-2.0.so:${PORTSDIR}/devel/glib20

CONFLICTS=	irssi-devel-[0-9]* zh-irssi-[0-9]*

USES=		pkgconfig ncurses gmake tar:bzip2 libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ncurses=${NCURSESBASE}

OPTIONS_DEFINE=	PERL PROXY SOCKS IPV6 BOT DOCS
SOCKS_DESC=	Socks proxy support
BOT_DESC=	Bot support
OPTIONS_DEFAULT=	PERL IPV6 DOCS

# USE_OPENSSL must be defined before bsd.port.pre.mk so use old schema
# for WITH_SSL option

.if defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	--disable-ssl
.else
USE_OPENSSL=	yes
.endif

.include <bsd.port.options.mk>

# Process options.

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

.if !${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--disable-ipv6
CATEGORIES+=	ipv6
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
