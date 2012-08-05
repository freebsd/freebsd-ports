# New ports collection makefile for:	undernet-ircu
# Date created:				2004-2-17
# Whom:					Walter Venable <weaseal@users.sourceforge.net>
#
# $FreeBSD$

PORTNAME=	undernet-ircu
PORTVERSION=	2.10.12.14
CATEGORIES=	irc net
MASTER_SITES=	SF/${PORTNAME}/ircu/ircu${PORTVERSION}
DISTNAME=	ircu${PORTVERSION}

MAINTAINER=	weaseal@users.sourceforge.net
COMMENT=	Undernet IRCU irc daemon

CONFLICTS=	ircd-hybrid-7.[0-9]*

USERS=		undernet
GROUPS=		${USERS}

GNU_CONFIGURE=		yes
USE_RC_SUBR=		undernet
CONFIGURE_ARGS=		--with-dpath=${PREFIX}/etc/ --with-symlink=no

PLIST_FILES=	bin/ircd bin/umkpasswd bin/convert-conf etc/ircd.conf.example

OPTIONS=	IPV6 "Disable IPv6 support (default is autodetect)" off \
		POLL "Force poll to be used even if not a sys call" off \
		DEBUG "Turn on debugging mode" off \
		ASSERTS "Disable assertion checking" off \
		PROFILE "Enable profiling support" off \
		PEDANTIC "Enable pedantic warnings" off \
		WARNINGS "Enable warnings (add -Wall to CFLAGS)" off \
		INLINES "Disable inlining for a few critical functions" off \
		DEVPOLL "Disable the /dev/poll-based engine" off \
		KQUEUE "Disable the kqueue-based engine" off \
		EPOLL "Disable the epoll-based engine" off \
		LEAKDETECT "Turn on the leak detector (reqs patched boehm)" off

.include <bsd.port.pre.mk>

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--without-ipv6
.endif

.if defined(WITH_POLL)
CONFIGURE_ARGS+=	--enable-poll
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_ASSERTS)
CONFIGURE_ARGS+=	--disable-asserts
.endif

.if defined(WITH_PROFILE)
CONFIGURE_ARGS+=	--enable-profile
.endif

.if defined(WITH_PEDANTIC)
CONFIGURE_ARGS+=	--enable-pedantic
.endif

.if defined(WITH_WARNINGS)
CONFIGURE_ARGS+=	--enable-warnings
.endif

.if defined(WITH_INLINES)
CONFIGURE_ARGS+=	--disable-inlines
.endif

.if defined(WITH_DEVPOLL)
CONFIGURE_ARGS+=	--disable-devpoll
.endif

.if defined(WITH_KQUEUE)
CONFIGURE_ARGS+=	--disable-kqueue
.endif

.if defined(WITH_EPOLL)
CONFIGURE_ARGS+=	--disable-epoll
.endif

.if defined(WITH_LEAKDETECT)
CONFIGURE_ARGS+=	--with-leak-detect
.endif

post-install:
	@${ECHO_MSG}    ""
	@${ECHO_MSG}    "	To run undernet ircu you must add 'undernet_enable=\"YES\" to"
	@${ECHO_MSG}    "	\"/etc/rc.conf\" .  It can then be started with"
	@${ECHO_MSG}	"	\"${PREFIX}/etc/rc.d/undernet start\""
	@${ECHO_MSG}    ""
	@${ECHO_MSG}    "	You must also copy \"${PREFIX}/etc/ircd.conf.example\" to"
	@${ECHO_MSG}    "	\"${PREFIX}/etc/ircd.conf\" and modify its settings according to"
	@${ECHO_MSG}    "	your needs.  See documentation at http://coder-com.undernet.org."
	@${ECHO_MSG}    ""

.include <bsd.port.post.mk>
