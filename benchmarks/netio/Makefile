# New ports collection Makefile for:		netio
# Date created:					2005-01-09
# Whom:						arved
#
# $FreeBSD$

PORTNAME=	netio
PORTVERSION=	1.14
CATEGORIES=	benchmarks net
MASTER_SITES=	http://www.netfuse.de/techarea/netio/
DISTNAME=	netio114

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network benchmark

WRKSRC=		${WRKDIR}
USE_ZIP=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
ALL_TARGET=	unix
PLIST_FILES=	bin/netio

post-patch:
	${REINPLACE_CMD} -e "s,-lsocket,," ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/netio ${PREFIX}/bin

.include <bsd.port.mk>
