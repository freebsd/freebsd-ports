# New ports collection makefile for:	xquarto
# Date created:				9 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xquarto
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://www.math.lsa.umich.edu/~mattiasj/games/xquarto/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X version of simple but tricky board game

USE_IMAKE=	yes
USE_XPM=	yes
MAN6=		xquarto.6
PLIST_FILES=	bin/xquarto

pre-configure:
	@${ECHO_CMD} "MANSUFFIX=6" >>${WRKSRC}/src/Imakefile

.include <bsd.port.mk>
