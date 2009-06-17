# New ports collection makefile for:	uftp
# Date created:				4 June 2008
# Whom:					George V. Neville-Neil <gnn@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	uftp
PORTVERSION=	2.9.1
CATEGORIES=	ftp
MASTER_SITES=	http://www.tcnj.edu/~bush/
DISTNAME=	uftp
EXTRACT_SUFX=	.tar
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A multicast capable FTP client and server

USE_GMAKE=	yes
MAKEFILE=	makefile
WRKSRC=		${WRKDIR}

PLIST_FILES=	bin/uftp bin/uftpd

MAN1=		uftp.1 uftpd.1
MANCOMPRESSED=	no

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uftp ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/uftpd ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/uftp.1 ${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/uftpd.1 ${MANPREFIX}/man/man1/

.include <bsd.port.mk>
