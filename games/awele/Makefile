# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	awele
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	games tk
MASTER_SITES=	XCONTRIB/games
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	African board game

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		imake tk tar:tgz xorg
USE_XORG=	x11
MAKE_ARGS=	AWELE_DIR=${STAGEDIR}${PREFIX}/bin

PLIST_FILES=	bin/awelewish bin/xawele man/man6/xawele.6.gz

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|; \
		 s|%%TK_VER%%|${TK_VER:S/.//}|; \
		 s|%%TCL_VER%%|${TCL_VER:S/.//}|; \
		 s|%%TK_INCLUDEDIR%%|${TK_INCLUDEDIR}|; \
		 s|%%TCL_INCLUDEDIR%%|${TCL_INCLUDEDIR}|' ${WRKSRC}/Imakefile

.include <bsd.port.mk>
