# Created by: Natacha Porte <natbsd@instinctive.eu>
# $FreeBSD$

PORTNAME=	ddns
PORTVERSION=	1.0
CATEGORIES=	dns
MASTER_SITES=	http://instinctive.eu/code/

MAINTAINER=	natbsd@instinctive.eu
COMMENT=	Lightweight UDP-based dynamic DNS updater

LICENSE=	ISCL

MAKEFILE=	BSDmakefile
USES=	tar:bzip2

USE_RC_SUBR=	ddns_client ddns_server

SUB_FILES=	pkg-message
PLIST_FILES=	sbin/ddns-server sbin/ddns-client \
		etc/ddns_client.conf.sample etc/ddns_server.conf.sample

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ddns-client ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/ddns-server ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${FILESDIR}/ddns_client.conf.sample \
		${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${FILESDIR}/ddns_server.conf.sample \
		${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
