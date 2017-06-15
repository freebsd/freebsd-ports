# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	dq
PORTVERSION=	20161210
CATEGORIES=	dns

MAINTAINER=	pkubaj@anongoth.pl
COMMENT=	Recursive DNS/DNSCurve server

LICENSE=	PD

RUN_DEPENDS=	envuidgid:sysutils/daemontools

OPTIONS_DEFINE=	DOCS

USE_GITHUB=	yes
GH_ACCOUNT=	janmojzis

USERS=		dq
GROUPS=		dq
SUB_FILES=	run
SUB_LIST=	ETCDIR="${ETCDIR}" UID="${USERS}" GID="${GROUPS}"

do-build:
	${MAKE_CMD} -C ${WRKSRC} compile
	${STRIP_CMD} ${WRKSRC}/build/bin/*

do-install:
	cd ${WRKSRC}/build/bin && ${COPYTREE_BIN} . ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/build/include && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/
	${MKDIR} ${STAGEDIR}${ETCDIR}cache/env ${STAGEDIR}${ETCDIR}cache/root/servers
	${ECHO_CMD} 10000000 > ${STAGEDIR}${ETCDIR}cache/env/CACHESIZE
	${ECHO_CMD} 127.0.0.1 > ${STAGEDIR}${ETCDIR}cache/env/IP
	${ECHO_CMD} "${ETCDIR}cache/root" > ${STAGEDIR}${ETCDIR}cache/env/ROOT
	${CP} files/root-servers-list ${STAGEDIR}${ETCDIR}cache/root/servers/@
	${CP} ${WRKDIR}/run ${STAGEDIR}${ETCDIR}cache/run
	${INSTALL_LIB} ${WRKSRC}/build/lib/libtinynacl.a ${STAGEDIR}${PREFIX}/lib

do-install-DOCS-on:
	${GZIP_CMD} ${WRKSRC}/build/man/*
	${INSTALL_MAN} ${WRKSRC}/build/man/dq*.1.gz ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/build/man/dq*.8.gz ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
