# Ports collection makefile for:  mscompress
# Date created:			  15 Apr 2000
# Whom:				  Patrick Seal <patseal@hyperhost.net>
#
# $FreeBSD$
#

PORTNAME=	mscompress
PORTVERSION=	0.3
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR= utils/compress

MAINTAINER=	patseal@hyperhost.net

USE_BZIP2=	yes
HAS_CONFIGURE=	yes

MAN1=		mscompress.1 msexpand.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mscompress ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/msexpand ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mscompress.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/msexpand.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
