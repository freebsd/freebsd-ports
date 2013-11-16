# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	exmars
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://corewar.co.uk/ankerl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Memory Array Redcode Simulator, just like exhaust and pMARS

REINPLACE_ARGS=	-i ''
ALL_TARGET=	${PORTNAME}

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS

.include <bsd.port.options.mk>

post-patch:
# Fix bench.sh.
	@${REINPLACE_CMD} -e 's|pmars|pmars-server| ; \
		s|\./exmars|exmars|' \
		${WRKSRC}/bench.sh

# Enable/disable compilation optimizations.
.if ! ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
	@${REINPLACE_CMD} -e 's|$${OPT}|${CFLAGS}|' ${WRKSRC}/${MAKEFILE}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -R ${WRKSRC}/warriors ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bench.sh ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
