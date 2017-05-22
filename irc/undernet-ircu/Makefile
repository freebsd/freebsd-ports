# Created by: Walter Venable <weaseal@users.sourceforge.net>
# $FreeBSD$

PORTNAME=	undernet-ircu
PORTVERSION=	2.10.12.16
CATEGORIES=	irc net
MASTER_SITES=	SF/${PORTNAME}/ircu/ircu${PORTVERSION} \
		ftp://ftpmirror.uk/freebsd-ports/undernet-ircu/
DISTNAME=	ircu${PORTVERSION}

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Undernet IRCU irc daemon

LICENSE=	GPLv1
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS=	ircd-hybrid-7.[0-9]*

USERS=		undernet
GROUPS=		${USERS}

GNU_CONFIGURE=	yes
USE_RC_SUBR=	undernet
SUB_FILES=	pkg-message
PORTDOCS=	*
PLIST_FILES=	bin/undernet-convert-conf \
		bin/undernet-umkpasswd \
		etc/ircd.conf.sample \
		sbin/ircd

CONFIGURE_ARGS+=	--with-dpath=${PREFIX}/etc/ --with-symlink=no

OPTIONS_DEFINE=	DOCS IPV6 POLL DEBUG ASSERTS PEDANTIC WARNINGS \
		INLINES DEVPOLL KQUEUE EPOLL LEAKDETECT
OPTIONS_DEFAULT=ASSERTS INLINES DEVPOLL KQUEUE EPOLL
POLL_DESC=	Force poll to be used even if not a sys call
ASSERTS_DESC=	Enable assertion checking
PEDANTIC_DESC=	Enable pedantic warnings
WARNINGS_DESC=	Enable warnings (add -Wall to CFLAGS)
INLINES_DESC=	Enable inlining for a few critical functions
DEVPOLL_DESC=	Enable the /dev/poll-based engine
KQUEUE_DESC=	Enable the kqueue-based engine
EPOLL_DESC=	Enable the epoll-based engine
LEAKDETECT_DESC=	Turn on the leak detector (reqs patched boehm)

IPV6_CONFIGURE_WITH=		ipv6
POLL_CONFIGURE_ENABLE=		poll
DEBUG_CONFIGURE_ENABLE=		debug
EPOLL_CONFIGURE_ENABLE=		epoll
KQUEUE_CONFIGURE_ENABLE=	kqueue
ASSERTS_CONFIGURE_ENABLE=	asserts
INLINES_CONFIGURE_ENABLE=	inlines
DEVPOLL_CONFIGURE_ENABLE=	devpoll
PEDANTIC_CONFIGURE_ENABLE=	pedantic
WARNINGS_CONFIGURE_ENABLE=	warnings
LEAKDETECT_CONFIGURE_WITH=	leak-detect

.if !defined(NO_PROFILE)
CONFIGURE_ARGS+=	--enable-profile
.endif

BROKEN_aarch64=		Fails to compile: undefined reference to .mcount

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ircd/ircd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/ircd/convert-conf \
		${STAGEDIR}${PREFIX}/bin/undernet-convert-conf
	${INSTALL_PROGRAM} ${WRKSRC}/ircd/umkpasswd \
		${STAGEDIR}${PREFIX}/bin/undernet-umkpasswd
	${INSTALL_DATA} ${WRKSRC}/doc/example.conf \
		${STAGEDIR}${PREFIX}/etc/ircd.conf.sample

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/api ${STAGEDIR}${DOCSDIR}/history
	(cd ${WRKSRC} && ${INSTALL_DATA} ChangeLog.11 ChangeLog.12 INSTALL \
		INSTALL_FR README RELEASE.NOTES ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} Authors debug_memleak_gc.patch \
		example.conf fda.txt features.txt freebsd.txt iso-time.html \
		linux-poll.patch p10.html readme.asll readme.chroot \
		readme.crules readme.cvs readme.features readme.gline \
		readme.iauth readme.indent readme.jupe readme.log readme.who \
		readme.www readme.xquery rfc1413.txt rfc1459.unet \
		snomask.html strings.txt ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/doc/api && ${INSTALL_DATA} api.txt events.txt \
		features.txt gline.txt ircd_snprintf.txt joinbuf.txt \
		jupe.txt log.txt modebuf.txt motd.txt msgq.txt \
		privileges.txt send.txt ${STAGEDIR}${DOCSDIR}/api)
	(cd ${WRKSRC}/doc/history && ${INSTALL_DATA} 2.4.notes README-2.6 \
		2.7-New ChangeLog.07 ChangeLog.10 Manual README.patches \
		history.pre24 overview.u2.9 ${STAGEDIR}${DOCSDIR}/history)

.include <bsd.port.mk>
