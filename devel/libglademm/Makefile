# Created by: Alexander Nedotsukov <bland@mail.ru>
# $FreeBSD$

PORTNAME=	libglademm
PORTVERSION=	2.1.3
PORTREVISION=	10
CATEGORIES=	devel gnome
MASTER_SITES=	SF/gtkmm/OldFiles
DIST_SUBDIR=	gnome2

MAINTAINER=	bland@FreeBSD.org
COMMENT=	C++ wrapper for libglade2 library

LIB_DEPENDS=	gtkmm-2.0:${PORTSDIR}/x11-toolkits/gtkmm20
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_XORG=	x11 sm
USES=		gmake pkgconfig
USE_GNOME=	gnomehack libglade2
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-static

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/examples//' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
