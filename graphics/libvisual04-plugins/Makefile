# New ports collection makefile for:	libvisual04-plugins
# Date created:		8 February 2007
# Whom:			Björn König <bkoenig@alpha-tierchen.de>
#
# $FreeBSD$
#

PORTNAME=	libvisual
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	libvisual
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
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

MAJORMINOR=	${PORTVERSION:C/.[0-9]+$//}

DATADIR=	${PREFIX}/share/${PORTNAME}-${PKGNAMESUFFIX:C/.*-//}-${MAJORMINOR}
PLIST_SUB=	PLUGINS_BASE_DIR=${LOCALBASE}/lib/${PORTNAME}-${MAJORMINOR} \
		DATADIR_REL=${DATADIR_REL}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
BROKEN=		Does not compile on 5.x
.endif

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

.include <bsd.port.post.mk>
