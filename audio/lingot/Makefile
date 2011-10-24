# New ports collection makefile for:	lingot
# Date created:		2011-10-17
# Whom:			Bartoletti <coder@tuxfamily.org>
#
# $FreeBSD$
#

PORTNAME=	lingot
PORTVERSION=	0.9.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=${PORTNAME}

MAINTAINER=	coder@tuxfamily.org
COMMENT=	LINGOT is a musical instrument tuner

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GNOME=	gtk20 libglade2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes

LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS=	JACK	"Enable jack plugin" on \
		ALSA	"Enable alsa plugin" off

.include <bsd.port.options.mk>

.if defined(WITH_JACK)
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack \
		samplerate.1:${PORTSDIR}/audio/libsamplerate
CONFIGURE_ARGS+=--enable-jack
.else
CONFIGURE_ARGS+=--disable-jack
.endif

.if defined(WITH_ALSA)
LIB_DEPENDS+=	asound.2:${PORTSDIR}/audio/alsa-lib
RUN_DEPENDS+=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins
CONFIGURE_ARGS+=--enable-alsa
.else
CONFIGURE_ARGS+=--disable-alsa
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 802502 || (${OSVERSION} > 900000 && ${OSVERSION} < 900027)
EXTRA_PATCHES+=	${FILESDIR}/extra-lingot-config-scale.h
.endif

.include <bsd.port.post.mk>
