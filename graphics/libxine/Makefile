# New ports collection makefile for:    libxine
# Date created:         14 Oct 2000
# Whom:                 alex
#
# $FreeBSD$
#

PORTNAME=	xine
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://xine.sourceforge.net/files/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	lib
DISTNAME=	${PORTNAME}-lib-${PORTVERSION}

MAINTAINER=	nobutaka@nobutaka.com

LIB_DEPENDS=	aa.1:${PORTSDIR}/graphics/aalib

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_IMLIB=	yes
USE_ESOUND=	yes
CONFIGURE_ARGS=	--with-w32-path=${LOCALBASE}/lib/win32
INSTALLS_SHLIB=	yes

MAN1=		xine-config.1
MAN3=		ao_driver_t.3 ao_functions_t.3 autoplay_group.3 \
		browse_group.3 build_info.3 cfg_data_t.3 config_group.3 \
		config_values_s.3 config_values_t.3 demux_strategy.3 \
		event_group.3 loadplugins_group.3 mrl_t.3 mrl_types.3 \
		status_group.3 ui_callbacks.3 version_group.3 video_cap.3 \
		video_group.3 video_prop.3 video_ratio.3 visual_types.3 \
		vo_driver_s.3 vo_driver_t.3 vo_frame_t.3 vo_overlay_t.3 \
		xine-lib.3 xine.h.3 xine_api.3 xine_init.3 xine_management.3 \
		xine_t.3 xine_version.3

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} >= 4
PLIST_SUB=	HAVE_LIBXV=""
.else
PLIST_SUB=	HAVE_LIBXV="@comment "
.endif

.if exists(${LOCALBASE}/bin/artsc-config)
PLIST_SUB+=	HAVE_ARTS=""
.else
PLIST_SUB+=	HAVE_ARTS="@comment "
.endif

.include <bsd.port.post.mk>
