# New ports collection makefile for:	undernet-ircu
# Date created:				2004-2-17
# Whom:					Walter Venable <weaseal@users.sourceforge.net>
#
# $FreeBSD$

PORTNAME=	undernet-ircu
PORTVERSION=	2.10.11.06
CATEGORIES=	irc net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	undernet-ircu
DISTNAME=	ircu${PORTVERSION}

MAINTAINER=	weaseal@users.sourceforge.net
COMMENT=	Undernet IRCU irc daemon

CONFLICTS=	ircd-hybrid*

GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--with-dpath=${PREFIX}/etc --with-symlink=no

PLIST_FILES=	bin/chkconf bin/ircd etc/ircd.conf.example

MAN8=		ircd.8

.include <bsd.port.pre.mk>

pre-everything::

	@${ECHO} ""
	@${ECHO} "Here is a list of possible configuration options:"
	@${ECHO} "(Note that options already selected will not be shown)"
	@${ECHO} ""

.if defined(ENABLE_POLL)
CONFIGURE_ARGS+=	--enable-poll
.else
	@${ECHO} "	ENABLE_POLL: Force poll to be used regardless of whether or not"
	@${ECHO} "	             it is a system call."
.endif

.if defined(ENABLE_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.else
	@${ECHO} "	ENABLE_DEBUG: Turn on debugging mode."
.endif

.if defined(DISABLE_ASSERTS)
CONFIGURE_ARGS+=	--disable-asserts
.else
	@${ECHO} "	DISABLE_ASSERTS: Disable assertion checking."
.endif

.if defined(DISABLE_SYMBOLS)
CONFIGURE_ARGS+=	--disable-symbols
.else
	@${ECHO} "	DISABLE_SYMBOLS: Disable debugging symbols (remove -g from CFLAGS)."
.endif

.if defined(ENABLE_PROFILE)
CONFIGURE_ARGS+=	--enable-profile
.else
	@${ECHO} "	ENABLE_PROFILE: Enable profiling support (add -pg to CFLAGS)."
.endif

.if defined(ENABLE_PEDANTIC)
CONFIGURE_ARGS+=	--enable-pedantic
.else
	@${ECHO} "	ENABLE_PEDANTIC: Enable pedantic warnings (add -pedantic to CFLAGS)."
.endif

.if defined(ENABLE_WARNINGS)
CONFIGURE_ARGS+=	--enable-warnings
.else
	@${ECHO} "	ENABLE_WARNINGS: Enable warnings (add -Wall to CFLAGS)."
.endif

.if defined(DISABLE_INLINES)
CONFIGURE_ARGS+=	--disable-inlines
.else
	@${ECHO} "	DISABLE_INLINES: Disable inlining for a few critical functions."
.endif

.if defined(DISABLE_DEVPOLL)
CONFIGURE_ARGS+=	--disable-devpoll
.else
	@${ECHO} "	DISABLE_DEVPOLL: Disable the /dev/poll-based engine."
.endif

.if defined(DISABLE_KQUEUE)
CONFIGURE_ARGS+=	--disable-kqueue
.else
	@${ECHO} "	DISABLE_KQUEUE: Disable the kqueue-based engine."
.endif

.if defined(DISABLE_EPOLL)
CONFIGURE_ARGS+=	--disable-epoll
.else
	@${ECHO} "	DISABLE_EPOLL: Disable the epoll-based engine."
.endif
	@${ECHO} ""
	@${ECHO} "To select any of these options CTRL+C now!  Then, for example: "
	@${ECHO} "	'make ENABLE_OPTION=1'."
	@${ECHO} ""
post-install:
	@ ${ECHO} ""
	@ ${ECHO} "	PLEASE NOTE:"
	@ ${ECHO} "	When you 'make deinstall', a binary file will remain in ${PREFIX}/bin"
	@ ${ECHO} "	with the name ircd.YEAR-MONTH-DAY-HOUR-MINUTE (of install).  This file"
	@ ${ECHO} "	must be removed manually."
	@ ${ECHO} ""

.include <bsd.port.post.mk>
