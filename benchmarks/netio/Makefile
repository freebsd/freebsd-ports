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
USES=		gmake zip
PLIST_FILES=	bin/netio

CFLAGS+=	-DUNIX
LIBS+=		-pthread
MAKE_ENV+=	OUT=-o

OPTIONS_DEFINE=	IPV6
IPV6_PLIST_FILES=	bin/netio6

.include <bsd.port.options.mk>

do-build:
	@(cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} O=.o CFLAGS="${CFLAGS}" ${MAKE_CMD} all)
.if ${PORT_OPTIONS:MIPV6}
	@(cd ${WRKSRC} && \
	${MAKE_ENV} O=.6o X=6 CFLAGS="${CFLAGS} -DUSE_IPV6" ${MAKE_CMD} all)
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/netio ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MIPV6}
	${INSTALL_PROGRAM} ${WRKSRC}/netio6 ${STAGEDIR}${PREFIX}/bin
.endif

.include <bsd.port.mk>
