# New ports collection makefile for:	amarok
# Date created:			Tue Feb 24 02:21:14 CET 2004
# Whom:				Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	amarok
PORTVERSION=	1.2.4
PORTREVISION=	1
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Media player for KDE

LIB_DEPENDS=	tag.4:${PORTSDIR}/audio/taglib \
		tunepimp:${PORTSDIR}/audio/libtunepimp

USE_BZIP2=	yes
USE_KDEBASE_VER=3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_SDL=	sdl

OPTIONS=	ARTS "aRts playback engine" off \
		GSTREAMER "GStreamer playback engine (includes aRts-output)" on \
		XINE "Xine playback engine" off \
		XMMS "XMMS visualizations" off \
		LIBVISUAL "libvisual support" off \
		OPENGL "OpenGL support" on \
		AMAZON "Amazon cover fetching support" on \
		MYSQL "Use MySQL as collection backend" off \
		AKODE "Akode playback engine" off

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
USE_GSTREAMER+=	mad vorbis flac musepack artsd
PLIST_SUB+=	GSTREAMER=""
.endif

.if defined(WITHOUT_XINE)
CONFIGURE_ARGS+=--without-xine
PLIST_SUB+=	XINE="@comment "
.else
LIB_DEPENDS+=	xine.13:${PORTSDIR}/multimedia/libxine
PLIST_SUB+=	XINE=""
.endif

.if defined(WITHOUT_XMMS)
PLIST_SUB+=	XMMS="@comment "
.else
BUILD_DEPENDS+=	xmms-config:${PORTSDIR}/multimedia/xmms
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms
PLIST_SUB+=	XMMS=""
.endif

.if defined(WITHOUT_LIBVISUAL)
PLIST_SUB+=	LIBVISUAL="@comment "
.else
LIB_DEPENDS+=	visual.0:${PORTSDIR}/graphics/libvisual
PLIST_SUB+=	LIBVISUAL=""
.endif

.if defined(WITHOUT_OPENGL)
CONFIGURE_ARGS+=--without-opengl
.endif

.if defined(WITHOUT_AMAZON)
CONFIGURE_ARGS+=--without-amazon
.endif

.if !defined(WITHOUT_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=--enable-mysql
.endif

.if defined(WITHOUT_AKODE)
CONFIGURE_ARGS+=--without-akode
PLIST_SUB+=	AKODE="@comment "
.else
CONFIGURE_ARGS+=--with-akode
LIB_DEPENDS+=	akode:${PORTSDIR}/audio/akode
PLIST_SUB+=	AKODE=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g'	${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|xx||g' ${WRKSRC}/po/Makefile.in
	@${REINPLACE_CMD} -e 's|SDL/SDL.h|SDL11/SDL.h|g' \
		${WRKSRC}/amarok/src/vis/libvisual/libvisual.h
	@${REINPLACE_CMD} -e 's|-lSDL|-lSDL-1.1 ${PTHREAD_LIBS}|g' \
		${WRKSRC}/amarok/src/vis/libvisual/Makefile.in
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${TOUCH}

post-configure:
.if defined(WITHOUT_XMMS)
	@${REINPLACE_CMD} -e '/XMMS /d' ${WRKSRC}/config.h
	@${REINPLACE_CMD} -e 's/xmmswrapper//g' ${WRKSRC}/amarok/src/vis/Makefile
.endif
.if defined(WITHOUT_LIBVISUAL)
	@${REINPLACE_CMD} -e '/LIBVISUAL /d' ${WRKSRC}/config.h
	@${REINPLACE_CMD} -e 's/libvisual//g' ${WRKSRC}/amarok/src/vis/Makefile
.endif

.include <bsd.port.post.mk>
