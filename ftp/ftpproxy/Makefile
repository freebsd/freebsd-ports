# New ports collection makefile for:	ftpproxy
# Date created:				15 May 2001
# Whom:					Philippe Le Berre <philippe@le-berre.com>
#
# $FreeBSD$
#

PORTNAME=	ftpproxy
PORTVERSION=	1.1.4
CATEGORIES=	ftp
MASTER_SITES=	http://www.ftpproxy.org/download/ \
		ftp://ftp.daemons.de/ \
		http://www.ftpproxy.org/download/older_releases/ \
		ftp://ftp.daemons.de/older_releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	philippe@le-berre.com

WRKSRC=		${WRKDIR}/${DISTNAME}/src

MAN1=		ftp.proxy.1
MANCOMPRESSED=	no

pre-patch:
	@${RM} -Rf ${WRKSRC}/*.o ${WRKSRC}/src/ftp.proxy
	@${PERL} -pi.orig -e 's|SOL_TCP|SOL_SOCKET|' ${WRKSRC}/ftp.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ftp.proxy ${PREFIX}/sbin
	@${INSTALL_MAN} ${WRKSRC}/../doc/ftp.proxy.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
