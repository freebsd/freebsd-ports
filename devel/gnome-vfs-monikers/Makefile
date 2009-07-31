# New ports collection makefile for:	gnome-vfs-monikers
# Date created:		2006-07-11
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/devel/gnome-vfs-monikers/Makefile,v 1.4 2006/07/18 11:37:57 ahze Exp $

PORTNAME=	gnome-vfs-monikers
PORTVERSION=	2.15.3
PORTREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome-vfs monikers module

USE_GNOME=	gnomevfs2 libbonobo
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

.include <bsd.port.mk>
