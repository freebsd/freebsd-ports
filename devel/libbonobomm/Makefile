# New ports collection makefile for:    libbonobomm
# Date created:         22 May 2003
# Whom:                 Alexander Nedotsukov <bland@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	libbonobomm
PORTVERSION=	1.3.8
PORTREVISION=	11
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	bland@FreeBSD.org
COMMENT=	C++ interfaces for libbonobo

LIB_DEPENDS=	gtkmm-2.0:${PORTSDIR}/x11-toolkits/gtkmm20 \
		ORBit-2-cpp.9:${PORTSDIR}/devel/orbitcpp
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack lthack libbonobo
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-static

post-patch:
	@${REINPLACE_CMD} -e 's|-lcpp|-l cpp|' ${WRKSRC}/bonobomm/generated/Makefile.in

.include <bsd.port.mk>
