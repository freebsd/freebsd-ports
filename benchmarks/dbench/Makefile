# New ports collection makefile for:	dbench
# Date created:		18 Febrary 2002
# Whom:			Andrew Shevtsov <nyxo@dnuc.polyn.kiae.su>
#
# $FreeBSD$
#

PORTNAME=	dbench
PORTVERSION=	1.3
CATEGORIES=	benchmarks
MASTER_SITES=	http://samba.org/ftp/tridge/dbench/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simulation of the Ziff-Davis netbench benchmark

WRKSRC=		${WRKDIR}/dbench
USE_REINPLACE=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
PLIST_FILES=	bin/dbench bin/tbench bin/tbench_srv

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PLIST_FILES:T} ${PREFIX}/bin

.include <bsd.port.mk>
