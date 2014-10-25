# Created by: "Waitman Gobble" <uzimac@da3m0n8t3r.com>
# $FreeBSD$
# New ports collection makefile for: multiraw
# Date created: 29 March 2013

PORTNAME=	multiraw
PORTVERSION=	1.0
CATEGORIES=	graphics
MASTER_SITES=	GH
DISTNAME=	${GH_ACCOUNT}-${GH_PROJECT}-${PORTVERSION}-0-g${GH_COMMIT}

MAINTAINER=	waitman@waitman.net
COMMENT=	Parallel process Camera RAW files using pthreads

LICENSE=	MULTIRAW
LICENSE_NAME=	MULTIRAW BSD LICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

DEPRECATED=	Depends on broken and deprecated graphics/dcraw-m
EXPIRATION_DATE=	2014-11-26

RUN_DEPENDS=	${LOCALBASE}/bin/dcraw:${PORTSDIR}/graphics/dcraw \
		${LOCALBASE}/bin/dcraw-m:${PORTSDIR}/graphics/dcraw-m

USE_GITHUB=	yes
GH_ACCOUNT=	waitman
GH_PROJECT=	multiraw
GH_COMMIT=	71a7651
GH_TAGNAME=	${GH_COMMIT}

WRKSRC=		${WRKDIR}/waitman-multiraw-${GH_COMMIT}

PLIST_FILES=	bin/multiraw man/man7/multiraw.7.gz
PORTDOCS=	*

WITH_PTHREAD=	yes

OPTIONS_DEFINE=	OPTIMIZE_O3 DOCS
OPTIMIZE_O3_DESC=	Use O3 Optimization

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPTIMIZE_O3}
CFLAGS+=	-O3
.endif

CFLAGS+=	-std=c99 -pthread

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/multiraw ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN}     ${WRKSRC}/multiraw.7 ${STAGEDIR}${PREFIX}/man/man7/
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
