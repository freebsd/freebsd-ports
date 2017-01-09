# $FreeBSD$

PORTNAME=	irssi
PORTVERSION=	0.8.21
PORTEPOCH=	1
PORTREVISION?=	0
CATEGORIES?=	irc
MASTER_SITES=	https://github.com/irssi/irssi/releases/download/${PORTVERSION}/

MAINTAINER?=	vanilla@FreeBSD.org
COMMENT?=	Modular IRC client with many features

LICENSE=	GPLv2

CONFLICTS=	irssi-devel-[0-9]* zh-irssi-[0-9]*

USES=		cpe gettext-runtime gmake libtool ncurses pkgconfig tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ncurses=${NCURSESBASE}
INSTALL_TARGET=	install-strip
USE_GNOME=	glib20

OPTIONS_DEFINE=	PERL PROXY SOCKS IPV6 BOT DOCS TRUECOLOR
OPTIONS_DEFAULT=	PERL
OPTIONS_SUB=	yes
SOCKS_DESC=	Socks proxy support
SOCKS_CONFIGURE_WITH=	socks
BOT_DESC=	Bot support
BOT_CONFIGURE_WITH=	bot
PERL_USES=	perl5
PERL_CONFIGURE_ON=	--with-perl-lib=site
PERL_CONFIGURE_OFF=	--with-perl=no
PROXY_CONFIGURE_WITH=	proxy
IPV6_CONFIGURE_ENABLE=	ipv6 
IPV6_CATEGORIES=	ipv6
TRUECOLOR_DESC=	Truecolor (24bit) support
TRUECOLOR_CONFIGURE_ENABLE=	true-color

.if defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	--disable-ssl
.else
USES+=		ssl
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' -e 's|/etc|${PREFIX}&|' \
		${WRKSRC}/docs/irssi.1

post-configure:
	@${MV} ${WRKSRC}/irssi.conf ${WRKSRC}/irssi.conf.sample

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/irssi/modules

post-install-PERL-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Irssi/Irssi.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Irssi/Irc/Irc.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Irssi/TextUI/TextUI.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Irssi/UI/UI.so

.include <bsd.port.mk>
