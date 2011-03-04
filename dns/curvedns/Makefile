# New ports collection makefile for: curvedns
# Date created:		11 Januari 2011
# Whom:			Leo Vandewoestijne <freebsd@dns-lab.com>
#
# $FreeBSD$
#

PORTNAME=		curvedns
PORTVERSION=		0.88.b
CATEGORIES=		dns
MASTER_SITES=		http://curvedns.on2it.net/releases/
DISTNAME=		curvedns-0.88-unstable

MAINTAINER=		freebsd@dns-lab.com
COMMENT=		A forwarder adding DNSCurve to an authoritive nameserver

LIB_DEPENDS=		ev.3:${PORTSDIR}/devel/libev
RUN_DEPENDS=		setuidgid:${PORTSDIR}/sysutils/daemontools
BUILD_DEPENDS=		bash:${PORTSDIR}/shells/bash

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	configure.nacl
ALL_TARGET=		# yes, an empty target.

CURVE_USER=		bind
CURVE_GROUP=		bind
CURVE_UID=		53
CURVE_GID=		53

SUB_FILES=		pkg-install pkg-message pkg-deinstall
SUB_LIST=		CURVE_USER=${CURVE_USER} \
			CURVE_GROUP=${CURVE_GROUP} \
			CURVE_UID=${CURVE_UID} \
			CURVE_GID=${CURVE_GID}

post-patch:
	@cd ${WRKSRC} && ${PATCH} --quiet < ${FILESDIR}/freebsd.patch

pre-configure:
	@${ECHO_MSG} "===>   configuring may take a couple of minutes"

post-configure:
	@cd ${WRKSRC} && ./configure.curvedns

post-install:
	${CP} ${WRKSRC}/curvedns ${WRKSRC}/curvedns-keygen ${PREFIX}/bin/
	${MKDIR} ${PREFIX}/etc/curvedns/log ${PREFIX}/etc/curvedns/env
	${CP} ${WRKSRC}/contrib/curvedns-run ${PREFIX}/etc/curvedns/run
	${CP} ${WRKSRC}/contrib/curvedns-log-run ${PREFIX}/etc/curvedns/log/run
	${ECHO} ${CURVE_UID} > ${PREFIX}/etc/curvedns/env/UID
	${ECHO} ${CURVE_GID} > ${PREFIX}/etc/curvedns/env/GID
	${CHOWN} -R ${CURVE_UID}:${CURVE_GID} ${PREFIX}/etc/curvedns
	${CHMOD} 755 ${PREFIX}/etc/curvedns/run ${PREFIX}/etc/curvedns/log/run
	${CHMOD} 0700 ${PREFIX}/etc/curvedns/env
	${SH} ${PKGINSTALL}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
