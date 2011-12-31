# New ports collection makefile for:	linuxsampler
# Date created:		2007-01-24
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	linuxsampler
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://download.linuxsampler.org/packages/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modular MIDI sampler

LIB_DEPENDS=	gig.10:${PORTSDIR}/audio/libgig

RESTRICTED=	no commercial use

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	"not yet ported"

OPTIONS=	JACK "Enable JACK support" on \
		ALSA "Enable ALSA support" off \
		ARTS "Enable aRts support" off \
		DSSI "Enable DSSI support" off \
		LV2CORE "Enable LV2 support" off

USE_BZIP2=	yes
USE_GNOME=	gnomehack
USE_SQLITE=	3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ENV=	HAVE_UNIX98=1
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		linuxsampler.1

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if defined(WITHOUT_JACK)
CONFIGURE_ARGS+=--disable-jack-driver
.else
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
.endif

.if defined(WITH_ALSA)
LIB_DEPENDS+=	asound.2:${PORTSDIR}/audio/alsa-lib
.else
CONFIGURE_ARGS+=--disable-alsa-driver
.endif

.if defined(WITH_ARTS)
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
.else
CONFIGURE_ARGS+=--disable-arts-driver
.endif

.if defined(WITH_DSSI)
BUILD_DEPENDS+=	dssi>=0:${PORTSDIR}/audio/dssi
RUN_DEPENDS+=	dssi>=0:${PORTSDIR}/audio/dssi
PLIST_SUB+=	DSSI=""
.else
CONFIGURE_ENV+=	ac_cv_header_dssi_h=no
PLIST_SUB+=	DSSI="@comment "
.endif

.if defined(WITH_LV2CORE)
BUILD_DEPENDS+=	lv2core>=0:${PORTSDIR}/audio/lv2core
RUN_DEPENDS+=	lv2core>=0:${PORTSDIR}/audio/lv2core
PLIST_SUB+=	LV2CORE=""
.else
CONFIGURE_ENV+=	ac_cv_header_lv2_h=no
PLIST_SUB+=	LV2CORE="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|CXX_CPU_SWITCH=.*|CXX_CPU_SWITCH=|g ; \
		 s|"lv2core"|"_lv2core_"|' ${WRKSRC}/configure

post-install:
	@${TOUCH} ${PREFIX}/lib/linuxsampler/plugins/.keep_me

.include <bsd.port.post.mk>
