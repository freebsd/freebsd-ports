# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-common
PORTVERSION=	3.18.0
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Common automake macros for GNOME 3

BUILD_DEPENDS=	autoconf-archive>=0:devel/autoconf-archive
RUN_DEPENDS=	autoconf-archive>=0:devel/autoconf-archive

USES=		gmake gnome pkgconfig tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-autoconf-archive

.include <bsd.port.mk>
