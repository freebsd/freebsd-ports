# -*-mode: makefile-*-
# New ports collection makefile for:	aRts
# Date created:				18 February 2002
# Whom:					will@cvs.kde.org
#
# $FreeBSD$
#

PORTNAME=	arts
PORTVERSION=	1.4.0
PORTEPOCH=	1
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${KDE_VERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Audio system for the KDE integrated X11 desktop

LIB_DEPENDS+=	audiofile:${PORTSDIR}/audio/libaudiofile \
		mad:${PORTSDIR}/audio/libmad \
		ogg:${PORTSDIR}/audio/libogg \
		glib:${PORTSDIR}/devel/glib20 \
		vorbis:${PORTSDIR}/audio/libvorbis

WANT_GNOME=	yes
USE_QT_VER=	3
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
QTCPPFLAGS+=	-L${LOCALBASE}/lib
USE_REINPLACE=	yes
DO_NOT_COMPILE+=gmcop
_NO_KDE_FINAL=	yes

CFLAGS+=	-DHAVE_VASPRINTF
CONFIGURE_ENV+=	DO_NOT_COMPILE="${DO_NOT_COMPILE}"
CONFIGURE_TARGET= # empty
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL} \
		--x-libraries=${X11BASE}/lib --x-includes=${X11BASE}/include

OPTIONS=	ESD "Enable esound support" off \
		NAS "Enable NAS support" off

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" || ${ARCH} == "amd64"
.if (${OSVERSION} < 500000 ) || (${OSVERSION} > 502102 )
LIB_DEPENDS+=	jack:${PORTSDIR}/audio/jack
.endif
.endif

.if defined(WITH_ESD)
USE_GNOME+=	esound
.endif

.if defined(WITH_NAS)
LIB_DEPENDS+=	audio:${PORTSDIR}/audio/nas
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's|-O2||g' -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
.if defined(WITHOUT_ESD)
	${REINPLACE_CMD} -e 's|arts_libesd_include=yes|arts_libesd_include=no|g' \
		${WRKSRC}/configure
.endif

.if defined(WITH_NAS)
	${REINPLACE_CMD} \
		-e 's|LIBS="-laudio  $$LIBS"|LIBS="-laudio -lm -lXt -lXau $$LIBS"|g' \
			${WRKSRC}/configure
.elseif defined(WITHOUT_NAS)
	${REINPLACE_CMD} \
		-e 's|ac_cv_lib_audio_AuOpenServer=yes|ac_cv_lib_audio_AuOpenServer=no|g' \
			${WRKSRC}/configure
.endif

post-configure:
	${TOUCH} ${WRKSRC}/mcop/arts_export.h.in
	${TOUCH} ${WRKSRC}/artsc/artsc_export.h.in

.include <bsd.port.post.mk>
