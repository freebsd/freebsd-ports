# New ports collection makefile for:   scwm-icons
# Date created:        07 April 1998
# Whom:                Yukihiro Nakai <nacai@iname.com>
#
# $FreeBSD$
#

PORTNAME=	scwm-icons
PORTVERSION=	0.99.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	scwm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An icon collection for the scwm window manager

USE_X_PREFIX=	yes

NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/share/scwm/pixmaps
.for dir in icons mini-icons startup
	${INSTALL_DATA} ${WRKSRC}/${dir}/*.xpm ${PREFIX}/share/scwm/pixmaps
.endfor

.include <bsd.port.mk>
