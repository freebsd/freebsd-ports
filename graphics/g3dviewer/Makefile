# ex:ts=8
# Ports collection makefile for:	g3dviewer
# Date created:			May 30, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	g3dviewer
PORTVERSION=	0.0.3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://madsworld.exhome.de/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A 3D file viewer for GTK+

LIB_DEPENDS=	gtkgl:${PORTSDIR}/x11-toolkits/gtkglarea

USE_GNOME=	gtk12
USE_MESA=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	\
	CPPFLAGS="${PTHREAD_CFLAGS} `${GTK_CONFIG} --cflags`" \
	LDFLAGS="${PTHREAD_LIBS} `${GTK_CONFIG} --libs` -lGL -lGLU -lglut"

.include <bsd.port.mk>
