# New ports collection makefile for:	mserver
# Date created:		21 May 1999
# Whom:		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mserver
PORTVERSION=	0.23a
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.innet.be/pub/staff/carl/

MAINTAINER=	sobomax@FreeBSD.org

do-install:
	${MKDIR} ${PREFIX}/share/doc/mserver
	${INSTALL_PROGRAM} ${WRKSRC}/mserver ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/tcpconn ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/mserver.conf ${PREFIX}/etc/mserver.conf.default
	${INSTALL_SCRIPT} ${WRKSRC}/mserver.sh.sample ${PREFIX}/etc/rc.d/mserver.sh.sample
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/mserver
	${INSTALL_MAN} ${WRKSRC}/README.tcpconn ${PREFIX}/share/doc/mserver

.include <bsd.port.mk>
