# Created by: Piotr Kubaj <pkubaj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dq
PORTVERSION=	20180112
CATEGORIES=	dns

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Recursive DNS/DNSCurve server

LICENSE=	PD

RUN_DEPENDS=	envuidgid:sysutils/daemontools

USE_GITHUB=	yes
GH_ACCOUNT=	janmojzis

USERS=		dq
GROUPS=		dq
SUB_FILES=	run
SUB_LIST=	ETCDIR="${ETCDIR}" UID="${USERS}" GID="${GROUPS}"
ALL_TARGET=	compile

do-install:
	cd ${WRKSRC}/build/bin && ${INSTALL_PROGRAM} * ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/build/include && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/
	${MKDIR} ${STAGEDIR}${ETCDIR}cache/env ${STAGEDIR}${ETCDIR}cache/root/servers
	${ECHO_CMD} 10000000 > ${STAGEDIR}${ETCDIR}cache/env/CACHESIZE
	${ECHO_CMD} 127.0.0.1 > ${STAGEDIR}${ETCDIR}cache/env/IP
	${ECHO_CMD} "${ETCDIR}cache/root" > ${STAGEDIR}${ETCDIR}cache/env/ROOT
	${CP} files/root-servers-list ${STAGEDIR}${ETCDIR}cache/root/servers/@
	${CP} ${WRKDIR}/run ${STAGEDIR}${ETCDIR}cache/run
	${INSTALL_DATA} ${WRKSRC}/build/lib/libtinynacl.a ${STAGEDIR}${PREFIX}/lib

	${INSTALL_MAN} ${WRKSRC}/build/man/dq*.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/build/man/dq*.8 ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
