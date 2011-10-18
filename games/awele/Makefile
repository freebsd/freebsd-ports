# New ports collection makefile for:	awele
# Date created:		01 May 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	awele
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	games tk
MASTER_SITES=	XCONTRIB/games
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An african board game

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_XORG=	x11
USE_IMAKE=	yes
USE_TCL_BUILD=	yes
USE_TK_BUILD=	yes
USE_TCL=	yes
USE_TK=		yes

MAN6=		xawele.6
PLIST_FILES=	bin/awelewish bin/xawele

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|; \
		 s|%%TK_VER%%|${TK_VER:S/.//}|; \
		 s|%%TCL_VER%%|${TCL_VER:S/.//}|; \
		 s|%%TK_INCLUDEDIR%%|${TK_INCLUDEDIR}|; \
		 s|%%TCL_INCLUDEDIR%%|${TCL_INCLUDEDIR}|' ${WRKSRC}/Imakefile

post-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Use xawele to start awele"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
