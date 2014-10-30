# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	exmars
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://corewar.co.uk/ankerl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Memory Array Redcode Simulator, just like exhaust and pMARS

ALL_TARGET=	${PORTNAME}

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS

OPTIMIZED_CFLAGS_CFLAGS=-O3 -fomit-frame-pointer

.include <bsd.port.options.mk>

post-patch:
# Fix bench.sh.
	@${REINPLACE_CMD} -e 's|pmars|pmars-server| ; \
		s|\./exmars|exmars|' \
		${WRKSRC}/bench.sh
	@${REINPLACE_CMD} -e 's|$${OPT}|${CFLAGS}|' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${COPYTREE_SHARE} warriors ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bench.sh ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
