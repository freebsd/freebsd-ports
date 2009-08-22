# New ports collection makefile for:	libvisual04-plugins
# Date created:		8 February 2007
# Whom:			Björn König <bkoenig@alpha-tierchen.de>
#
# $FreeBSD$
#

PORTNAME=	libvisual
PORTVERSION=	0.4.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-plugins/${PORTNAME}-plugins-${PORTVERSION}
PKGNAMESUFFIX=	04-plugins
DISTNAME=	${PORTNAME}-${PKGNAMESUFFIX:C/.*-//}-${PORTVERSION}

MAINTAINER=	bkoenig@alpha-tierchen.de
COMMENT=	Set of plugins for the libvisual framework

LIB_DEPENDS=	visual-${MAJORMINOR}:${PORTSDIR}/graphics/libvisual04

USE_GNOME=	pkgconfig
USE_GL=		yes
USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-alsa \
		--disable-mplayer \
		--disable-gstreamer-plugin \
		--disable-gdkpixbuf-plugin \
		--disable-gforce \
		--disable-jess \
		--prefix=${PREFIX}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAJORMINOR=	${PORTVERSION:C/.[0-9]+$//}

DATADIR=	${PREFIX}/share/${PORTNAME}-${PKGNAMESUFFIX:C/.*-//}-${MAJORMINOR}
PLIST_SUB=	PLUGINS_BASE_DIR=${LOCALBASE}/lib/${PORTNAME}-${MAJORMINOR} \
		DATADIR_REL=${DATADIR_REL}

pre-configure:
# /usr/bin/objformat is obsolete, hardcode the object format
	@${REINPLACE_CMD} -e 's,objformat=.*,objformat=elf,' \
		${WRKSRC}/configure
# link some plugins with libGLU because they need it
	@${REINPLACE_CMD} -e 's,^\(LDFLAGS = \),\1-lGLU ,' \
		${WRKSRC}/plugins/actor/lv_gltest/Makefile.in \
		${WRKSRC}/plugins/actor/nastyfft/Makefile.in \
		${WRKSRC}/plugins/actor/pseudotoad_flower/Makefile.in
# don't install message catalogs
	@${REINPLACE_CMD} -e 's,^\(SUBDIRS = plugins\) po,\1,' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
