# New ports collection makefile for:	irssi
# Date created:			14 Apr 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	irssi
PORTVERSION=	0.8.15
PORTREVISION=	1
CATEGORIES?=	irc
MASTER_SITES=	http://mirror.irssi.org/

MAINTAINER?=	vanilla@FreeBSD.org
COMMENT?=	A modular IRC client with many features

LIB_DEPENDS=	glib-2.0:${PORTSDIR}/devel/glib20

CONFLICTS=	irssi-devel-[0-9]* zh-irssi-[0-9]*

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WANT_PERL=	yes

MAN1=		irssi.1

OPTIONS=	PERL "Enable perl support" on \
		PROXY "Enable proxy support" off \
		SOCKS "Enable socks proxy support" off \
		IPV6 "Enable IPv6" on \
		BOT "Enable bot" off
# USE_OPENSSL must be defined before bsd.port.pre.mk so use old schema
# for WITH_SSL option

.if defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	--disable-ssl
.else
USE_OPENSSL=	yes
.endif

.include <bsd.port.pre.mk>

# Process options.

.if !defined(WITHOUT_PERL)
USE_PERL5=	yes
CONFIGURE_ARGS+=	--with-perl-lib=site
PLIST_SUB+=	WITH_PERL=""
.else
CONFIGURE_ARGS+=	--without-perl
PLIST_SUB+=	WITH_PERL="@comment "
.endif

.if defined(WITH_PROXY)
CONFIGURE_ARGS+=	--with-proxy
PLIST_SUB+=	WITH_PROXY=""
.else
PLIST_SUB+=	WITH_PROXY="@comment "
.endif

.if defined(WITH_SOCKS)
CONFIGURE_ARGS+=	--with-socks
.endif

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
CATEGORIES+=	ipv6
.endif

.if defined(WITH_BOT)
CONFIGURE_ARGS+=	--with-bot
PLIST_SUB+=	WITH_BOT=""
.else
CONFIGURE_ARGS+=	--without-bot
PLIST_SUB+=	WITH_BOT="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' -e 's|/etc|${PREFIX}&|' \
		${WRKSRC}/docs/irssi.1

post-configure:
	@${MV} ${WRKSRC}/irssi.conf ${WRKSRC}/irssi.conf.sample

post-install:
	@if [ ! -f ${PREFIX}/etc/irssi.conf ]; then \
		${ECHO} "Installing default configuration file."; \
		${INSTALL_DATA} ${WRKSRC}/irssi.conf.sample ${PREFIX}/etc/irssi.conf ; \
	fi
	@${ECHO_MSG} "You may install x11-themes/irssi-themes for"
	@${ECHO_MSG} " additional themes."

.include <bsd.port.post.mk>
