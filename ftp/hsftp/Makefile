# New ports collection makefile for:	hsftp
# Date created:				Mon 03 Jul 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	hsftp
PORTVERSION=	1.9
CATEGORIES=	ftp
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/network/file-transfer

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-readline
MAKEFILE=	makefile
MAN1=		hsftp.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hsftp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/hsftp.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
