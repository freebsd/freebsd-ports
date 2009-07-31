# New ports collection makefile for:	imlib
# Date created:		10 June 1997
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#    $MCom: ports/graphics/imlib/Makefile,v 1.2 2006/09/10 00:51:11 mezz Exp $
#

PORTNAME=	imlib
PORTVERSION=	1.9.15
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A graphic library for enlightenment package

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		ungif.5:${PORTSDIR}/graphics/libungif

USE_AUTOTOOLS=	libtool:15
USE_BZIP2=	yes
USE_XORG=	sm xext x11
USE_GMAKE=	yes
USE_GNOME=	gtk12 gnomehack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/imlib --disable-modules
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		imlib-config.1 imlib_config.1

pre-configure:
	@${REINPLACE_CMD} -e "s|10:15:9|5:0:0|" ${WRKSRC}/*/Makefile.in
	@${REINPLACE_CMD} -e "s|glib-config|${GLIB_CONFIG}|" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s|@SUPPORT_LIBS@|-L${LOCALBASE}/lib @SUPPORT_LIBS@|" ${WRKSRC}/imlib-config.in

.include <bsd.port.mk>
