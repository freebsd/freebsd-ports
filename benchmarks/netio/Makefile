# Created by: arved
# $FreeBSD$

PORTNAME=	netio
PORTVERSION=	1.26
CATEGORIES=	benchmarks net ipv6
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	arved
DISTNAME=	netio126

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Network benchmark

WRKSRC=		${WRKDIR}
USE_ZIP=	yes
USES=		gmake
PLIST_FILES=	bin/netio

CFLAGS+=	-DUNIX ${PTHREAD_CFLAGS}
MAKE_ENV+=	OUT="-o" LIBS=${PTHREAD_LIBS}
.if defined(WITH_IPV6)
PLIST_FILES+=	bin/netio6
.endif

do-build:
	cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} O=.o CFLAGS="${CFLAGS}" ${GMAKE} all
.if defined(WITH_IPV6)
	cd ${WRKSRC}; \
	${MAKE_ENV} O=.6o X=6 CFLAGS="${CFLAGS} -DUSE_IPV6" ${GMAKE} all
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/netio ${PREFIX}/bin
.if defined(WITH_IPV6)
	${INSTALL_PROGRAM} ${WRKSRC}/netio6 ${PREFIX}/bin
.endif

.include <bsd.port.mk>
