# Created by: Walter Venable <weaseal@users.sourceforge.net>
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

OPTIONS_DEFINE=	IPV6 POLL DEBUG ASSERTS PROFILE PEDANTIC WARNINGS INLINES DEVPOLL KQUEUE \
		EPOLL LEAKDETECT
POLL_DESC=	Force poll to be used even if not a sys call
ASSERTS_DESC=	Disable assertion checking
PEDANTIC_DESC=	Enable pedantic warnings
WARNINGS_DESC=	Enable warnings (add -Wall to CFLAGS)
INLINES_DESC=	Disable inlining for a few critical functions
DEVPOLL_DESC=	Disable the /dev/poll-based engine
KQUEUE_DESC=	Disable the kqueue-based engine
EPOLL_DESC=	Disable the epoll-based engine
LEAKDETECT_DESC=	Turn on the leak detector (reqs patched boehm)

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--with-ipv6
.else
CONFIGURE_ARGS+=	--without-ipv6
.endif

.if ${PORT_OPTIONS:MPOLL}
CONFIGURE_ARGS+=	--enable-poll
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
.endif

.if ${PORT_OPTIONS:MASSERTS}
CONFIGURE_ARGS+=	--disable-asserts
.endif

.if ${PORT_OPTIONS:MPROFILE}
CONFIGURE_ARGS+=	--enable-profile
.endif

.if ${PORT_OPTIONS:MPEDANTIC}
CONFIGURE_ARGS+=	--enable-pedantic
.endif

.if ${PORT_OPTIONS:MWARNINGS}
CONFIGURE_ARGS+=	--enable-warnings
.endif

.if ${PORT_OPTIONS:MINLINES}
CONFIGURE_ARGS+=	--disable-inlines
.endif

.if ${PORT_OPTIONS:MDEVPOLL}
CONFIGURE_ARGS+=	--disable-devpoll
.endif

.if ${PORT_OPTIONS:MKQUEUE}
CONFIGURE_ARGS+=	--disable-kqueue
.endif

.if ${PORT_OPTIONS:MEPOLL}
CONFIGURE_ARGS+=	--disable-epoll
.endif

.if ${PORT_OPTIONS:MLEAKDETECT}
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

.include <bsd.port.mk>
