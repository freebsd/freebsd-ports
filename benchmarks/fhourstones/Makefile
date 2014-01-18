# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	fhourstones
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	http://homepages.cwi.nl/~tromp/c4/
DISTNAME=	Fhourstones

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Fhourstones Benchmark

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/fhourstones lib/fhourstones/SearchGame lib/fhourstones/inputs
PLIST_DIRS=	lib/fhourstones

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/fhourstones

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/fhourstones
	${INSTALL_SCRIPT} ${WRKDIR}/fhourstones ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/SearchGame ${STAGEDIR}${PREFIX}/lib/fhourstones
	${INSTALL_DATA} ${WRKDIR}/inputs ${STAGEDIR}${PREFIX}/lib/fhourstones

.include <bsd.port.mk>
