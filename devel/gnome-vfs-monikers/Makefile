# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/devel/gnome-vfs-monikers/Makefile,v 1.4 2006/07/18 11:37:57 ahze Exp $

PORTNAME=	gnome-vfs-monikers
PORTVERSION=	2.15.3
PORTREVISION=	10
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome-vfs monikers module

USE_GNOME=	gnomevfs2 libbonobo
USES=		gmake pkgconfig
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib #-pthread

NO_STAGE=	yes
.include <bsd.port.mk>
