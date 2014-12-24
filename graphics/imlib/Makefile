# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
# $FreeBSD$
#    $MCom: ports/graphics/imlib/Makefile,v 1.2 2006/09/10 00:51:11 mezz Exp $

PORTNAME=	imlib
PORTVERSION=	1.9.15
PORTREVISION=	18
CATEGORIES=	graphics
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Graphic library for enlightenment package

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libgif.so:${PORTSDIR}/graphics/giflib

USES=		gmake libtool pathfix tar:bzip2
USE_XORG=	sm xext x11
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/imlib --disable-modules
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
