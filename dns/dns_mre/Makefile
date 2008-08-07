# New ports collection makefile for:	dns_mre
# Date created:		2008-08-02
# Whom:			Tomoyuki Sakurai <cherry@trombik.org>
#
# $FreeBSD$
#

PORTNAME=	dns_mre
PORTVERSION=	1.0
CATEGORIES=	dns security
MASTER_SITES=	http://www.securebits.org/tools/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	cherry@trombik.org
COMMENT=	DNS Cache Poisoner/Overwriter

NO_WRKSUBDIR=	Yes

PLIST_FILES=	bin/dns_mre

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -Wall main.c dns_mre.c -o dns_mre

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dns_mre ${PREFIX}/bin/

.include <bsd.port.mk>
