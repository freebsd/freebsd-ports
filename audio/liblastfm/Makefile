# Created by: Matt Tosto <datahead4@gmail.com>
# $FreeBSD$

PORTNAME=	liblastfm
PORTVERSION=	1.0.6
#PORTREVISION=	0
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt C++ library for the Last.fm webservices

LICENSE=	GPLv3

LIB_DEPENDS=	libfftw3.so:${PORTSDIR}/math/fftw3 \
		libfftw3f.so:${PORTSDIR}/math/fftw3-float \
		libsamplerate.so:${PORTSDIR}/audio/libsamplerate

GH_ACCOUNT=	lastfm
GH_COMMIT=	5826fe6
GH_PROJECT=	liblastfm
GH_TAGNAME=	${PORTVERSION}

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=		FINGERPRINT TESTS
FINGERPRINT_DESC=	Build the lastfm-fingerprint library
TESTS_DESC=		Build liblastfm tests
OPTIONS_DEFAULT=	FINGERPRINT

USES=		cmake pkgconfig
NO_STAGE=	yes
USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_QT4=	dbus moc_build rcc_build network qmake_build qtestlib sql xml

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFINGERPRINT}
CMAKE_ARGS+=	-DBUILD_FINGERPRINT:BOOL=ON
PLIST_SUB+=	FINGERPRINT=""
.else
CMAKE_ARGS+=	-DBUILD_FINGERPRINT:BOOL=OFF
PLIST_SUB+=	FINGERPRINT="@comment "
.endif

.if ${PORT_OPTIONS:MTESTS}
CMAKE_ARGS+=	-DBUILD_TESTS:BOOL=ON
.else
CMAKE_ARGS+=	-DBUILD_TESTS:BOOL=OFF
.endif

.include <bsd.port.mk>
