# New ports collection makefile for:	eterm-bg
# Date created:        99/06/12
# Whom:                Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	eterm-bg
PORTVERSION=	0.9.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.eterm.org/download/
DISTNAME=	Eterm-bg-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Image files for background of Eterm

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_X_PREFIX=	yes

do-install:
	${MKDIR} ${PREFIX}/share/Eterm
	${MKDIR} ${PREFIX}/share/Eterm/pix
	${MKDIR} ${PREFIX}/share/Eterm/pix/scale
	${MKDIR} ${PREFIX}/share/Eterm/pix/tile
	${INSTALL_DATA} ${WRKSRC}/bg/scale/*  ${PREFIX}/share/Eterm/pix/scale
	${INSTALL_DATA} ${WRKSRC}/bg/tile/*  ${PREFIX}/share/Eterm/pix/tile

.include <bsd.port.mk>
