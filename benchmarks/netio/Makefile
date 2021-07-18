# Created by: arved

PORTNAME=	netio
PORTVERSION=	1.33
CATEGORIES=	benchmarks net
MASTER_SITES=	http://www.ars.de/ \
		LOCAL/arved
DISTNAME=	netio133

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Network benchmark

USES=		dos2unix gmake zip

LICENSE=	UNKNOWN
LICENSE_NAME=	unknown
LICENSE_TEXT=	Usage permitted for non-commercial purposes only. Sale for profit is not permitted.
LICENSE_PERMS=	auto-accept

DOS2UNIX_FILES=	Makefile netio.c
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/netio
CFLAGS+=	-DUNIX -DSOCKLEN_T
LIBS+=		-pthread
MAKE_ENV=	OUT=-o

OPTIONS_DEFINE=	IPV6
IPV6_PLIST_FILES=	bin/netio6

do-build:
	@(cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} O=.o CFLAGS="${CFLAGS}" ${MAKE_CMD} all)
do-build-IPV6-on:
	@(cd ${WRKSRC} && \
	${MAKE_ENV} O=.6o X=6 CFLAGS="${CFLAGS} -DUSE_IPV6" ${MAKE_CMD} all)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/netio ${STAGEDIR}${PREFIX}/bin
do-install-IPV6-on:
	${INSTALL_PROGRAM} ${WRKSRC}/netio6 ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
