# $FreeBSD$

PORTNAME=	pulseaudio-module-xrdp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1
CATEGORIES=	audio

MAINTAINER=	meta@FreeBSD.org
COMMENT=	PulseAudio module which enables xrdp to use audio redirection

LICENSE=	APACHE20

BUILD_DEPENDS=	${NONEXISTENT}:audio/pulseaudio:configure \
		${LOCALBASE}/include/xrdp_constants.h:net/xrdp
LIB_DEPENDS=	libpulse.so:audio/pulseaudio

USES=		autoreconf:build libtool pkgconfig
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	neutrinolabs
GH_PROJECT=	pulseaudio-module-xrdp

PLIST_FILES=	`${PULSE_MODDIR}`/module-xrdp-sink.so \
		`${PULSE_MODDIR}`/module-xrdp-source.so

CONFIGURE_ARGS=	PULSE_DIR=${WRKDIR}/pulseaudio-`${PULSE_VERSION}`

PULSE_VERSION=	pkg-config --modversion libpulse
PULSE_MODDIR=	pkg-config --variable=modlibexecdir libpulse
PULSE_WRKSRC=	${MAKE} -C ${PORTSDIR}/audio/pulseaudio -VWRKSRC

pre-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./bootstrap
	@${CP} -r "`${PULSE_WRKSRC}`" ${WRKDIR}

.include <bsd.port.mk>
