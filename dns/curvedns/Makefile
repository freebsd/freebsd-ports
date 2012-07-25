# New ports collection makefile for: curvedns
# Date created:		11 Januari 2011
# Whom:			Leo Vandewoestijne <freebsd@dns-lab.com>
#
# $FreeBSD$
#

PORTNAME=		curvedns
PORTVERSION=		0.88.b
PORTREVISION=		2
CATEGORIES=		dns
MASTER_SITES=		http://curvedns.on2it.net/releases/
DISTNAME=		curvedns-0.88-unstable

MAINTAINER=		freebsd@dns-lab.com
COMMENT=		Forwarder adding DNSCurve to an authoritative nameserver

LIB_DEPENDS=		ev.4:${PORTSDIR}/devel/libev
RUN_DEPENDS=		setuidgid:${PORTSDIR}/sysutils/daemontools
BUILD_DEPENDS=		bash:${PORTSDIR}/shells/bash

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	configure.nacl
ALL_TARGET=		# yes, an empty target.

USERS=			bind
GROUPS=			bind
CURVE_UID=		53
CURVE_GID=		53

SUB_FILES=		pkg-message

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

post-patch:
	@cd ${WRKSRC} && ${PATCH} --quiet < ${FILESDIR}/freebsd.patch

pre-configure:
	@${ECHO_MSG} "===>   configuring may take a couple of minutes"

post-configure:
.if ${ARCH} == "amd64"
	@cd ${WRKSRC} && ./configure.curvedns amd64
.else
	@cd ${WRKSRC} && ./configure.curvedns
.endif

post-install:
	${CP} ${WRKSRC}/curvedns ${WRKSRC}/curvedns-keygen ${PREFIX}/bin/
	${MKDIR} ${PREFIX}/etc/curvedns/log ${PREFIX}/etc/curvedns/env
	${CP} ${WRKSRC}/contrib/curvedns-run ${PREFIX}/etc/curvedns/run.sample
	${CP} ${WRKSRC}/contrib/curvedns-log-run ${PREFIX}/etc/curvedns/log/run.sample
	${ECHO_CMD} ${CURVE_UID} > ${PREFIX}/etc/curvedns/env/UID
	${ECHO_CMD} ${CURVE_GID} > ${PREFIX}/etc/curvedns/env/GID
	${CHOWN} -R ${CURVE_UID}:${CURVE_GID} ${PREFIX}/etc/curvedns
	${CHMOD} 755 ${PREFIX}/etc/curvedns/run.sample \
		${PREFIX}/etc/curvedns/log/run.sample
	${CHMOD} 0700 ${PREFIX}/etc/curvedns/env
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
