# New ports collection makefile for:	gtksheet
# Version required:		7.6
# Date created:			Jun 22 1999
# Whom:				Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

DISTNAME=	gtksheet-8.0
CATEGORIES=	devel
MASTER_SITES=	http://magnet.fsu.edu/~feiguin/gtk/src/

MAINTAINER=	ijliao@csie.nctu.edu.tw

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

USE_X_PREFIX=	yes
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
MAKE_ENV+=	GTK_CONFIG=${GTK_CONFIG}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libgtksheet.a ${PREFIX}/lib
	@${MKDIR} ${PREFIX}/include/gtksheet
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/gtksheet

.include <bsd.port.mk>
