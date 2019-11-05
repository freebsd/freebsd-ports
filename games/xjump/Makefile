# Created by: will
# $FreeBSD$

PORTNAME=	xjump
PORTVERSION=	2.7.5
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	DEBIAN_POOL
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple X game where one tries to jump up as many levels as possible

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/g}

USES=		xorg
USE_XORG=	xpm xaw
MAKE_ARGS=	CC="${CC} ${CFLAGS}" RECORD_FILE="/var/games/xjump.record" \
		IDIR="-I${LOCALBASE}/include" LDIR="-L${LOCALBASE}/lib"
ALL_TARGET=	xjump

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xjump ${STAGEDIR}${PREFIX}/bin
	@${ECHO_CMD} "@group games" >> ${TMPPLIST}
	@${ECHO_CMD} "@mode 2755" >> ${TMPPLIST}
	@${ECHO_CMD} "bin/xjump" >> ${TMPPLIST}
	@${ECHO_CMD} "@mode" >> ${TMPPLIST}
	@${ECHO_CMD} "@group" >> ${TMPPLIST}

.include <bsd.port.mk>
