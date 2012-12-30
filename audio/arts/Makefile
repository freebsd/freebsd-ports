# Created by: will@cvs.kde.org
# $FreeBSD$

PORTNAME=	arts
PORTVERSION=	1.5.10
PORTREVISION=	8
PORTEPOCH=	1
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${KDE_VERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Audio system for the KDE integrated X11 desktop

LIB_DEPENDS+=	asound:${PORTSDIR}/audio/alsa-lib \
		audiofile:${PORTSDIR}/audio/libaudiofile \
		mad:${PORTSDIR}/audio/libmad \
		ogg:${PORTSDIR}/audio/libogg \
		vorbis:${PORTSDIR}/audio/libvorbis \
		glib-2.0:${PORTSDIR}/devel/glib20 \
		pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		pcre:${PORTSDIR}/devel/pcre \
		jpeg:${PORTSDIR}/graphics/jpeg \
		lcms:${PORTSDIR}/graphics/lcms \
		mng:${PORTSDIR}/graphics/libmng \
		png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		xcb:${PORTSDIR}/x11/libxcb

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

PREFIX=		${KDE_PREFIX}
WANT_GNOME=	yes
USE_QT_VER=	3
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_ICONV=	yes
USE_XORG=	ice sm x11 xau xcursor xdmcp xext xfixes xft xi \
		xinerama xrandr xrender xt
USE_LDCONFIG=	yes
QTCPPFLAGS+=	-L${LOCALBASE}/lib
DO_NOT_COMPILE+=gmcop
_NO_KDE_FINAL=	yes

CFLAGS+=	-DHAVE_VASPRINTF
CONFIGURE_ENV+=	DO_NOT_COMPILE="${DO_NOT_COMPILE}"

OPTIONS_DEFINE=	ESOUND NAS

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" || ${ARCH} == "amd64"
LIB_DEPENDS+=	jack:${PORTSDIR}/audio/jack
.endif

.if ${PORT_OPTIONS:MESOUND}
USE_GNOME+=	esound
.endif

.if ${PORT_OPTIONS:MNAS}
LIB_DEPENDS+=	audio:${PORTSDIR}/audio/nas
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's|-O2||g' -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
.if defined(WITHOUT_ESD)
	${REINPLACE_CMD} -e 's|arts_libesd_include=yes|arts_libesd_include=no|g' \
		${WRKSRC}/configure
.endif

.if ${PORT_OPTIONS:MNAS}
	${REINPLACE_CMD} \
		-e 's|LIBS="-laudio  $$LIBS"|LIBS="-laudio -lm -lXt -lXau $$LIBS"|g' \
			${WRKSRC}/configure
.else
	${REINPLACE_CMD} \
		-e 's|ac_cv_lib_audio_AuOpenServer=yes|ac_cv_lib_audio_AuOpenServer=no|g' \
			${WRKSRC}/configure
.endif

post-configure:
	${TOUCH} ${WRKSRC}/mcop/arts_export.h.in
	${TOUCH} ${WRKSRC}/artsc/artsc_export.h.in

.include <bsd.port.post.mk>
