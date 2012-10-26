# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	xquarto
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.math.lsa.umich.edu/~mattiasj/games/xquarto/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X version of simple but tricky board game

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2012-11-26

USE_IMAKE=	yes
USE_XORG=	xaw
MAN6=		xquarto.6
PLIST_FILES=	bin/xquarto

pre-configure:
	@${ECHO_CMD} "MANSUFFIX=6" >>${WRKSRC}/src/Imakefile

.include <bsd.port.mk>
