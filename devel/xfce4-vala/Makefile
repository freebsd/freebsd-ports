# Created by: Olivier Duchateau <olivierd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xfce4-vala
PORTVERSION=	4.10.3
PORTREVISION=	5
CATEGORIES=	devel xfce
MASTER_SITES=	XFCE/src/bindings/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Vala binding for the Xfce core libraries

LICENSE=	LGPL21

BUILD_DEPENDS=	valac:lang/vala

USES=		gmake gnome pathfix pkgconfig tar:bzip2 xfce
USE_XFCE=	panel

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-vala-api=0.40

.include <bsd.port.mk>
