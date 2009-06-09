# New ports collection makefile for:	awele
# Date created:		01 May 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	awele
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	games tk
MASTER_SITES=	http://www-air.inria.fr/ftp/Jean-Paul/ \
		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games
DISTFILES=	${PORTNAME}1.0.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An african board game

USE_TCL_BUILD=	84
USE_TK_BUILD=	${USE_TCL_BUILD}
WRKSRC=		${WRKDIR}/awele
USE_IMAKE=	yes
USE_XORG=	x11
MAN6=		xawele.6
PLIST_FILES=	bin/awelewish bin/xawele

post-patch:
	${REINPLACE_CMD} -e "s|\@\@LOCALBASE\@\@|${LOCALBASE}|g;" ${WRKSRC}/Imakefile

post-install:
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Use xawele to start awele"
	@${ECHO_CMD} ""

.include <bsd.port.mk>
