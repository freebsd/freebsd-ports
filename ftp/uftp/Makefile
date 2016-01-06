# Created by: George V. Neville-Neil <gnn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	uftp
PORTVERSION=	4.8
PORTEPOCH=	1
CATEGORIES=	ftp
MASTER_SITES=	SF/uftp-multicast/source-zip
DISTNAME=	uftp_src-${DISTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Multicast capable FTP client and server

LICENSE=	GPLv3

MAKEFILE=	makefile
USES=		zip gmake
EXTRACT_BEFORE_ARGS=	-qoa	# -a to clean up DOS line endings

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uftp ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/uftpd ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/uftp_keymgt ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/uftpproxyd ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/uftp.1 ${STAGEDIR}${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/uftpd.1 ${STAGEDIR}${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/uftpproxyd.1 ${STAGEDIR}${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/uftp_keymgt.1 ${STAGEDIR}${MANPREFIX}/man/man1/

.include <bsd.port.mk>
