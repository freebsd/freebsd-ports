# New ports collection makefile for:	xamp
# Date created:			29 July 1998
# Whom:				Joe Jih-Shian Lu <jslu@dns.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	xamp
PORTVERSION=	0.8-7
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.simcb.ru/pub/unix/x11/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

USE_QT=		yes

WRKSRC=		${WRKDIR}/xamp-0.8/xamp-0.8
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes

MAN1=		xamp.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xamp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xamp.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
