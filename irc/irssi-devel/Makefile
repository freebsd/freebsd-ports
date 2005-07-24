# New ports collection makefile for:	irssi-devel
# Date created:                 03 Mar 2005
# Whom:                         Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	irssi
PORTVERSION=	20050720
CATEGORIES=	irc
MASTER_SITES=	http://highsecure.ru/
PKGNAMESUFFIX=	-devel

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	A modular IRC client with many features

CONFLICTS=	irssi-0.8*

GNU_CONFIGURE=	yes

USE_GNOME=	glib20
USE_LIBTOOL_VER=	15
USE_REINPLACE=	yes
USE_GMAKE=	yes

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

.if defined(WITH_PERL)
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

.if defined(WITH_IPV6)
.if ${OSVERSION} >= 400014
CONFIGURE_ARGS+=	--enable-ipv6
CATEGORIES+=	ipv6
.else
BROKEN=	"This version of FreeBSD does not support IPv6. Please use WITH_IPV6=no"
.endif
.endif

.if defined(WITH_BOT)
CONFIGURE_ARGS+=	--with-bot
.endif

post-configure:
	@${MV} ${WRKSRC}/irssi.conf ${WRKSRC}/irssi.conf.sample

post-install:
	@if [ ! -f ${PREFIX}/etc/irssi.conf ]; then \
		${ECHO} "Installing default configuration file."; \
		${INSTALL_DATA} ${WRKSRC}/irssi.conf.sample ${PREFIX}/etc/irssi.conf ; \
	fi

.include <bsd.port.post.mk>
