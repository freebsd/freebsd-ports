# New ports collection makefile for:	oneko
# Date created:				15/11/2002
# Whom:					Guido Falsi <mad@madpilot.net>
#
# $FreeBSD$
#

PORTNAME=	tdir
PORTVERSION=	1.17f
CATEGORIES=	games
MASTER_SITES=	http://www.backerstreet.com/traindir/
DISTNAME=	tdir117s

MAINTAINER=	mad@madpilot.net
COMMENT=	Train controller simulation

USE_ZIP=	yes
USE_XLIB=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk12 glib12
USE_REINPLACE=	yes

NO_WRKSUBDIR=	yes

post-extract:
	${REINPLACE_CMD} -e 's///' ${WRKSRC}/*

post-patch:
	@ cd ${WRKSRC} ; ${LN} MAKEFILE Makefile ; \
	${MV} Gdialog.c gdialog.c ; ${MV} Gtkopen.c gtkopen.c ; \
	${MV} Gtkopen.h gtkopen.h ; ${MV} Html.c html.c ; \
	${MV} Html.h html.h

post-configure:
	${REINPLACE_CMD} -e 's,\#include \<malloc.h\>,/* include malloc.h */,' \
		${WRKSRC}/gdialog.c
.include <bsd.port.mk>
