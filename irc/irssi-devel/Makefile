# New ports collection makefile for:	irssi
# Date created:			14 Apr 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	irssi
PORTVERSION=	0.8.6
PORTREVISION?=	3
CATEGORIES+=	irc	# `+=' is for slave ports
MASTER_SITES=	http://irssi.org/files/

MAINTAINER?=	vanilla@FreeBSD.org
COMMENT?=	A modular IRC client with many features

USE_BZIP2=	yes
USE_PERL5=	yes
USE_GNOME=	glib12
GNU_CONFIGURE=	yes
# `+=' is for slave ports
CONFIGURE_ARGS+=	--without-socks --without-bot --with-textui \
		--with-perl-lib=site

.include <bsd.port.pre.mk>

.if defined(WITH_PROXY)
CONFIGURE_ARGS+=	--with-proxy
PLIST_SUB+=	WITH_PROXY=""
.else
PLIST_SUB+=	WITH_PROXY="@comment "
.endif

.if defined(WITH_IPV6)
.if ${OSVERSION} >= 400014
CONFIGURE_ARGS+= --enable-ipv6
CATEGORIES+=	ipv6
.endif
.else
CONFIGURE_ARGS+= --disable-ipv6
.endif

MAN1=		irssi.1

pre-configure:
	@cd ${WRKSRC} && ${MV} irssi.conf irssi.conf.sample

post-install:
	@if [ ! -f ${LOCALBASE}/etc/irssi.conf ]; then \
		${ECHO} "Installing default configuration file."; \
		${INSTALL_DATA} ${WRKSRC}/irssi.conf.sample ${LOCALBASE}/etc/irssi.conf ; \
	fi

.include <bsd.port.post.mk>
