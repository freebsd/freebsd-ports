# New ports collection makefile for:	GtkGEP
# Date created:				Sun Jan 26 19:15:57 CST 2003
# Whom:					Mark Linimon <linimon@lonesome.com>
#
# $FreeBSD$
#

PORTNAME=	gtkgep
PORTVERSION=	0.2.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.macio.risp.pl/gtkgep/files/

MAINTAINER=	linimon@lonesome.com
COMMENT=	A guitar effects processor for GTK

USE_LIBTOOL_VER=	13
USE_GMAKE=	yes
USE_GNOME=	gtk12
CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS}"
PLIST_SUB=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
