# New ports collection makefile for:	irssi
# Date created:			14 Apr 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	irssi
PORTVERSION=	0.8.9
PORTREVISION?=	1
CATEGORIES?=	irc
MASTER_SITES=	http://irssi.org/files/

MAINTAINER?=	vanilla@FreeBSD.org
COMMENT?=	A modular IRC client with many features

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

WANT_GNOME=	yes

MAN1=		irssi.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Does not compile"
.endif

# Set option defaults.

.if ! defined(WITH_GLIB)
.if exists(${LOCALBASE}/include/glib-2.0/glib.h)
WITH_GLIB=	2
.else
WITH_GLIB=	1
.endif
.endif

.if ! defined(WITH_PERL)
WITH_PERL=	yes
.endif

.if ! defined(WITH_PROXY)
WITH_PROXY=	no
.endif

.if ! defined(WITH_SOCKS)
WITH_SOCKS=	no
.endif

.if ! defined(WITH_IPV6)
WITH_IPV6=	yes
.endif

.if ! defined(WITH_SSL)
WITH_SSL=	yes
.endif

.if ! defined(WITH_BOEHM_GC)
WITH_BOEHM_GC=	no
.endif

.if ! defined(WITH_BOT)
WITH_BOT=	no
.endif

# Process options.

.if ${WITH_GLIB} == "2"
USE_GNOME=	glib20
.elif ${WITH_GLIB} == "1"
CONFIGURE_ARGS+=	--with-glib1
USE_GNOME=	glib12
.else
.error WITH_GLIB must be set to "1" or "2".
.endif

.if ${WITH_PERL:L} == "yes"
USE_PERL5=	yes
CONFIGURE_ARGS+=	--with-perl-lib=site
PLIST_SUB+=	WITH_PERL=""
.else
CONFIGURE_ARGS+=	--without-perl
PLIST_SUB+=	WITH_PERL="@comment "
.endif

.if ${WITH_PROXY:L} == "yes"
CONFIGURE_ARGS+=	--with-proxy
PLIST_SUB+=	WITH_PROXY=""
.else
PLIST_SUB+=	WITH_PROXY="@comment "
.endif

.if ${WITH_SOCKS:L} == "yes"
CONFIGURE_ARGS+=	--with-socks
.endif

.if ${WITH_IPV6:L} == "yes"
.if ${OSVERSION} >= 400014
CONFIGURE_ARGS+=	--enable-ipv6
CATEGORIES+=	ipv6
.else
.error This version of FreeBSD does not support IPv6. Please use WITH_IPV6=no.
.endif
.endif

.if ${WITH_SSL:L} == "yes"
USE_OPENSSL=	yes
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

.if ${WITH_BOEHM_GC:L} == "yes"
LIB_DEPENDS+=	gc.1:${PORTSDIR}/devel/boehm-gc
CONFIGURE_ENV+=	CPPFLAGS=-I${PREFIX}/include
CONFIGURE_ARGS+=	--with-gc
.endif

.if ${WITH_BOT:L} == "yes"
CONFIGURE_ARGS+=	--with-bot
.endif

pre-extract:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "	WITH_GLIB=1|2		Select a GLib version to use [auto]"
	@${ECHO} "	WITH_PERL=yes|no	Enable Perl support [yes]"
	@${ECHO} "	WITH_PROXY=yes|no	Enable irssi-proxy [no]"
	@${ECHO} "	WITH_SOCKS=yes|no	Enable Socks support [no]"
	@${ECHO} "	WITH_IPV6=yes|no	Enable IPv6 support [yes]"
	@${ECHO} "	WITH_SSL=yes|no		Enable SSL support [yes]"
	@${ECHO} "	WITH_BOEHM_GC=yes|no	Enable GC support [no]"
	@${ECHO} "	WITH_BOT=yes|no		Enable BOT support [no]"
	@${ECHO} ""

pre-configure:
	@cd ${WRKSRC} && ${MV} irssi.conf irssi.conf.sample

post-install:
	@if [ ! -f ${LOCALBASE}/etc/irssi.conf ]; then \
		${ECHO} "Installing default configuration file."; \
		${INSTALL_DATA} ${WRKSRC}/irssi.conf.sample ${LOCALBASE}/etc/irssi.conf ; \
	fi

.include <bsd.port.post.mk>
