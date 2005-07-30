# New ports collection makefile for:  tictactoe3d
# Date created:       	Mon Apr 28 16:46:17 CEST 2003
# Whom:                Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$

PORTNAME=	tictactoe3d
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.che.iitm.ac.in/~ch99057/software/
DISTNAME=	ttt3d

DEPRECATED=	"master site disappeared"
EXPIRATION_DATE=2005-08-31

MAINTAINER=	ports@FreeBSD.org
COMMENT=	This is a simple "3D" tic tac toe game

PLIST_FILES=	bin/tictactoe3d
WRKSRC=		${WRKDIR}/ttt3d

USE_GMAKE=	yes
USE_GNOME=	gtk12

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttt ${PREFIX}/bin/tictactoe3d

.include <bsd.port.mk>
