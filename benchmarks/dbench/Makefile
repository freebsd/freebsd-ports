# New ports collection makefile for:	dbench
# Date created:		18 Febrary 2002
# Whom:			Andrew Shevtsov <nyxo@dnuc.polyn.kiae.su>
#
# $FreeBSD$
#

PORTNAME=	dbench
PORTVERSION=	1.3
CATEGORIES=	benchmarks
# ftp://samba.org/pub/tridge/dbench/ does not exist anymore. Asked
# tridge@samba.org for a new site - edwin 20021228
MASTER_SITES=	#

MAINTAINER=	nyxo@dnuc.polyn.kiae.su

WRKSRC=		${WRKDIR}/dbench
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's/^CFLAGS.+//g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dbench ${PREFIX}/bin/dbench
	${INSTALL_PROGRAM} ${WRKSRC}/tbench ${PREFIX}/bin/tbench
	${INSTALL_PROGRAM} ${WRKSRC}/tbench_srv ${PREFIX}/bin/tbench_srv

.include <bsd.port.mk>
