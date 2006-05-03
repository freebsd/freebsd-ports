# New ports collection Makefile for:		netio
# Date created:					2005-01-09
# Whom:						arved
#
# $FreeBSD$

PORTNAME=	netio
PORTVERSION=	1.14
PORTREVISION=	1
CATEGORIES=	benchmarks net ipv6
MASTER_SITES=	http://www.netfuse.de/techarea/netio/
DISTNAME=	netio114

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Network benchmark

WRKSRC=		${WRKDIR}
USE_ZIP=	yes
USE_GMAKE=	yes
PLIST_FILES=	bin/netio

.if defined(WITH_IPV6)
PLIST_FILES+=	bin/netio6
.endif

post-patch:
	${REINPLACE_CMD} -e "s,-lsocket,," ${WRKSRC}/Makefile

do-build:
	cd ${WRKSRC} && ${GMAKE} unix
.if defined(WITH_IPV6)
	cd ${WRKSRC} && ${GMAKE} unix6
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/netio ${PREFIX}/bin
.if defined(WITH_IPV6)
	${INSTALL_PROGRAM} ${WRKSRC}/netio6 ${PREFIX}/bin
.endif

.include <bsd.port.mk>
