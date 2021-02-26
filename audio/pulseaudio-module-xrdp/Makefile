# $FreeBSD$

PORTNAME=	pulseaudio-module-xrdp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5
CATEGORIES=	audio
DIST_SUBDIR=	xrdp

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/

MAINTAINER=	meta@FreeBSD.org
COMMENT=	PulseAudio module which enables xrdp to use audio redirection

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${NONEXISTENT}:audio/pulseaudio:configure
LIB_DEPENDS=	libpulse.so:audio/pulseaudio

USES=		autoreconf:build compiler:c11 libtool localbase pkgconfig
USE_GITHUB=	yes

GNU_CONFIGURE=	yes
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
