# New ports collection makefile for:	linux-unace
# Date created:				29 May 2003
# Whom:					fjoe@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	unace
PORTVERSION=	2.20
CATEGORIES=	archivers
MASTER_SITES=	http://ace.imptech.net/ \
		http://www.shedz.com/winace/ \
		http://hem.passagen.se/vanlid/winace/ \
		http://www.winace.mewa.net/mirror/ \
		http://home.hccnet.nl/h.edskes/download/ \
		http://www.maxeline.com/winace/
PKGNAMEPREFIX=	linux-
DISTNAME=	linunace22
EXTRACT_SUFX=	.tgz

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	ACE (un)archiver for Linux

USE_LINUX=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
STRIP=

do-install:
	brandelf -t Linux ${WRKSRC}/unace
	${INSTALL_PROGRAM} ${WRKSRC}/unace ${PREFIX}/bin/lunace

.include <bsd.port.mk>
