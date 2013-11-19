# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	awele
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	games tk
MASTER_SITES=	XCONTRIB/games
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	African board game

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		imake tk
USE_XORG=	x11

MAN6=		xawele.6
PLIST_FILES=	bin/awelewish bin/xawele

NO_STAGE=	yes
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
