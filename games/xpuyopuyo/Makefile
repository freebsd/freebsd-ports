# New ports collection makefile for:	xpuyopuyo
# Version required:	0.1.1
# Date created:		19 Sep 1999
# Whom:			Yin-Jieh Chen <yinjieh@csie.nctu.edu.tw>
#
# $FreeBSD$
#

DISTNAME=	xpuyopuyo-0.1.1
CATEGORIES=	games
MASTER_SITES=	http://chaos2.org/xpuyopuyo/

MAINTAINER=	yinjieh@csie.nctu.edu.tw

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xpuyopuyo ${PREFIX}/bin

post-install:
	@${MKDIR} ${PREFIX}/share/xpuyopuyo
.for i in AUTHORS COPYING ChangeLog INSTALL NEWS README TESTED TODO
	@${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/xpuyopuyo
.endfor
	@${MKDIR} ${PREFIX}/share/xpuyopuyo/img
	@${INSTALL_DATA} ${WRKSRC}/img/* ${PREFIX}/share/xpuyopuyo/img

.include <bsd.port.mk>
