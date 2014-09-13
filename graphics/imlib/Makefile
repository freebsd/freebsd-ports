# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
# $FreeBSD$
#    $MCom: ports/graphics/imlib/Makefile,v 1.2 2006/09/10 00:51:11 mezz Exp $

PORTNAME=	imlib
PORTVERSION=	1.9.15
PORTREVISION=	17
CATEGORIES=	graphics
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Graphic library for enlightenment package

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libgif.so:${PORTSDIR}/graphics/giflib

# TODO: Remove :oldver together with version-info patching in pre-configure.
USES=		gmake libtool:oldver pathfix tar:bzip2
USE_XORG=	sm xext x11
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/imlib --disable-modules
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libpng15
LDFLAGS+=	-L${LOCALBASE}/lib

pre-configure:
	@${REINPLACE_CMD} -e "s|10:15:9|5:0:0|" ${WRKSRC}/*/Makefile.in
	@${REINPLACE_CMD} -e "s|glib-config|${GLIB_CONFIG}|" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s|@SUPPORT_LIBS@|-L${LOCALBASE}/lib @SUPPORT_LIBS@|" ${WRKSRC}/imlib-config.in

.include <bsd.port.mk>
