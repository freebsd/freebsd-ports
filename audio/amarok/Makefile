# New ports collection makefile for:	amarok
# Date created:			Tue Feb 24 02:21:14 CET 2004
# Whom:				Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	amarok
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Media player for KDE

LIB_DEPENDS=    tag:${PORTSDIR}/audio/taglib

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

OPTIONS=	ARTS "aRts support" on \
		GSTREAMER "GStreamer support" off \
		XMMS "XMMS visualizations" on \
		OPENGL "OpenGL support" on \

.include <bsd.port.pre.mk>

.if defined(WITHOUT_ARTS)
CONFIGURE_ARGS+=--without-arts
PLIST_SUB+=	ARTS="@comment "
.else
LIB_DEPENDS+=	artsgui:${PORTSDIR}/multimedia/kdemultimedia3
PLIST_SUB+=	ARTS=""
.endif

.if defined(WITHOUT_GSTREAMER)
CONFIGURE_ARGS+=--without-gstreamer
PLIST_SUB+=	GSTREAMER="@comment "
.else
LIB_DEPENDS+=	gstplay-0.8.1:${PORTSDIR}/multimedia/gstreamer-plugins
PLIST_SUB+=	GSTREAMER=""
.endif

.if defined(WITHOUT_XMMS)
PLIST_SUB+=	XMMS="@comment "
.else
BUILD_DEPENDS+=	xmms-config:${PORTSDIR}/multimedia/xmms
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms
PLIST_SUB+=	XMMS=""
.endif

.if defined(WITHOUT_OPENGL)
CONFIGURE_ARGS+=--without-opengl
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g'	${WRKSRC}/${CONFIGURE_SCRIPT}

post-configure:
.if defined(WITHOUT_XMMS)
	@${REINPLACE_CMD} -e '/XMMS /d' ${WRKSRC}/config.h
.endif

.include <bsd.port.post.mk>
