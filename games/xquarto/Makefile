# New ports collection makefile for:	xquarto
# Version required:			1.0
# Date created:				9 March 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.2 1998/07/27 23:25:20 asami Exp $
#

DISTNAME=	xquarto-1.0
CATEGORIES=	games
MASTER_SITES=	http://www.math.kth.se/~mjo/games/xquarto/

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	Xpm.5:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
MAN6=		xquarto.6

pre-configure:
	@echo "MANSUFFIX=6" >>${WRKSRC}/src/Imakefile

.include <bsd.port.mk>
