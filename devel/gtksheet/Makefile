# New ports collection makefile for:	gtksheet
# Date created:			Jun 22 1999
# Whom:				Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	gtksheet
PORTVERSION=	8.0
CATEGORIES=	devel
MASTER_SITES=	http://magnet.fsu.edu/~feiguin/gtk/src/

MAINTAINER=	ijliao@csie.nctu.edu.tw

USE_X_PREFIX=	yes
USE_GTK=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libgtksheet.a ${PREFIX}/lib
	@${MKDIR} ${PREFIX}/include/gtksheet
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/gtksheet

.include <bsd.port.mk>
