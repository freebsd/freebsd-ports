# Created by: Leo Vandewoestijne <freebsd@dns-lab.com>
# $FreeBSD$

PORTNAME=	curvedns
PORTVERSION=	0.88.b
PORTREVISION=	6
CATEGORIES=	dns
DISTNAME=	curvedns-0.88-unstable

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Forwarder adding DNSCurve to an authoritative nameserver

LIB_DEPENDS=	libev.so:${PORTSDIR}/devel/libev \
		libsodium.so:${PORTSDIR}/security/libsodium
RUN_DEPENDS=	setuidgid:${PORTSDIR}/sysutils/daemontools
BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	vstakhov
GH_TAGNAME=	0.87
GH_COMMIT=	a88e27e

ALL_TARGET=	targets

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USERS=		bind
GROUPS=		bind
CURVE_UID=	53
CURVE_GID=	53

SUB_FILES=	pkg-message

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/curvedns ${WRKSRC}/curvedns-keygen ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/curvedns/log ${STAGEDIR}${PREFIX}/etc/curvedns/env
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/curvedns-run ${STAGEDIR}${PREFIX}/etc/curvedns/run.sample
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/curvedns-log-run ${STAGEDIR}${PREFIX}/etc/curvedns/log/run.sample
	${ECHO_CMD} ${CURVE_UID} > ${STAGEDIR}${PREFIX}/etc/curvedns/env/UID
	${ECHO_CMD} ${CURVE_GID} > ${STAGEDIR}${PREFIX}/etc/curvedns/env/GID

.include <bsd.port.mk>
