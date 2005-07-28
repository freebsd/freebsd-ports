# New ports collection makefile for:	ftpproxy
# Date created:				15 May 2001
# Whom:					Philippe Le Berre <philippe@le-berre.com>
#
# $FreeBSD$
#

PORTNAME=	ftpproxy
PORTVERSION=	1.2.3
CATEGORIES=	ftp
MASTER_SITES=	http://www.ftpproxy.org/download/ \
		http://www.ftpproxy.org/download/older_releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	philippe@le-berre.com
COMMENT=	A ftp proxy

USE_REINPLACE=	yes
USE_GMAKE=	yes
CFLAGS +=-DVERSION=\\\"${PORTVERSION}\\\"

MAN1=		ftp.proxy.1
MANCOMPRESSED=	no
PLIST_FILES=	sbin/ftp.proxy

pre-build:
	@${REINPLACE_CMD} -e 's|^CFLAGS|#CFLAGS|' ${WRKSRC}/src/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/ftp.proxy ${PREFIX}/sbin
	@${INSTALL_MAN} ${WRKSRC}/doc/ftp.proxy.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
