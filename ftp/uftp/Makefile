# New ports collection makefile for:	uftp
# Date created:				4 June 2008
# Whom:					George V. Neville-Neil <gnn@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	uftp
PORTVERSION=	3.3.1
PORTEPOCH=	1
CATEGORIES=	ftp
MASTER_SITES=	http://www.tcnj.edu/~bush/
EXTRACT_SUFX=	.tar

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A multicast capable FTP client and server

USE_GMAKE=	yes
MAKEFILE=	makefile

PLIST_FILES=	bin/uftp bin/uftp_keymgt sbin/uftpd sbin/uftpproxyd

MAN1=		uftp.1 uftpd.1 uftpproxyd.1 uftp_keymgt.1
MANCOMPRESSED=	no

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uftp ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/uftpd ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/uftp_keymgt ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/uftpproxyd ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/uftp.1 ${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/uftpd.1 ${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/uftpproxyd.1 ${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/uftp_keymgt.1 ${MANPREFIX}/man/man1/

.include <bsd.port.mk>
