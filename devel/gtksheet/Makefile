# New ports collection makefile for:	gtksheet
# Version required:		7.6
# Date created:			Jun 22 1999
# Whom:				Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $Id: Makefile,v 1.1.1.1 1999/06/06 17:29:46 steve Exp $
#

DISTNAME=	gtksheet-7.6
CATEGORIES=	devel
MASTER_SITES=	ftp://ripley.ifir.edu.ar/pub/gtk/gtksheet/

MAINTAINER=	ijliao@csie.nctu.edu.tw

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

USE_X_PREFIX=	yes
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
MAKE_ENV+=	GTK_CONFIG=${GTK_CONFIG}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libGtkSheet.a ${PREFIX}/lib

.include <bsd.port.mk>
