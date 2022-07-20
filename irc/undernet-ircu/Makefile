PORTNAME=	undernet-ircu
PORTVERSION=	2.10.12.19
CATEGORIES=	irc net
MASTER_SITES=	https://github.com/UndernetIRC/ircu2/releases/download/u${PORTVERSION}/ \
		ftp://ftpmirror.uk/freebsd-ports/undernet-ircu/
DISTNAME=	ircu${PORTVERSION}

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Undernet IRCU irc daemon

LICENSE=	GPLv1
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=		Fails to compile: undefined reference to .mcount
BROKEN_riscv64=		Fails to compile: undefined reference to .mcount

USE_GCC=	yes
USE_RC_SUBR=	undernet

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-dpath=${PREFIX}/etc/ --with-symlink=no

CONFLICTS=	ircd-hybrid-7.[0-9]*

SUB_FILES=	pkg-message

USERS=		undernet
GROUPS=		${USERS}

PLIST_FILES=	bin/undernet-convert-conf \
		bin/undernet-umkpasswd \
		etc/ircd.conf.sample \
		sbin/ircd
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS IPV6 POLL DEBUG ASSERTS PEDANTIC WARNINGS \
		INLINES DEVPOLL KQUEUE EPOLL LEAKDETECT
OPTIONS_DEFAULT=ASSERTS INLINES DEVPOLL KQUEUE EPOLL

ASSERTS_DESC=	Enable assertion checking
DEVPOLL_DESC=	Enable the /dev/poll-based engine
EPOLL_DESC=	Enable the epoll-based engine
INLINES_DESC=	Enable inlining for a few critical functions
KQUEUE_DESC=	Enable the kqueue-based engine
LEAKDETECT_DESC=	Turn on the leak detector (reqs patched boehm)
PEDANTIC_DESC=	Enable pedantic warnings
POLL_DESC=	Force poll to be used even if not a sys call
WARNINGS_DESC=	Enable warnings (add -Wall to CFLAGS)

ASSERTS_CONFIGURE_ENABLE=	asserts
DEBUG_CONFIGURE_ENABLE=		debug
DEVPOLL_CONFIGURE_ENABLE=	devpoll
EPOLL_CONFIGURE_ENABLE=		epoll
INLINES_CONFIGURE_ENABLE=	inlines
IPV6_CONFIGURE_WITH=		ipv6
KQUEUE_CONFIGURE_ENABLE=	kqueue
LEAKDETECT_CONFIGURE_WITH=	leak-detect
PEDANTIC_CONFIGURE_ENABLE=	pedantic
POLL_CONFIGURE_ENABLE=		poll
WARNINGS_CONFIGURE_ENABLE=	warnings

.if !defined(NO_PROFILE)
CONFIGURE_ARGS+=	--enable-profile
.endif

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
