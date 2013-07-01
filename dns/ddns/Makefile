# Created by: Natacha Porte <natbsd@instinctive.eu>
# $FreeBSD$

PORTNAME=	ddns
PORTVERSION=	1.0
CATEGORIES=	dns
MASTER_SITES=	http://instinctive.eu/code/

MAINTAINER=	natbsd@instinctive.eu
COMMENT=	Lightweight UDP-based dynamic DNS updater

LICENSE=	BSD

MAKEFILE=	BSDmakefile
USE_BZIP2=	yes

USE_RC_SUBR=	ddns_client ddns_server

SUB_FILES=	pkg-message
PLIST_FILES=	sbin/ddns-server sbin/ddns-client \
		etc/ddns_client.conf.sample etc/ddns_server.conf.sample

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ddns-client ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/ddns-server ${PREFIX}/sbin
	${INSTALL_DATA} ${FILESDIR}/ddns_client.conf.sample ${PREFIX}/etc
	${INSTALL_DATA} ${FILESDIR}/ddns_server.conf.sample ${PREFIX}/etc

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
