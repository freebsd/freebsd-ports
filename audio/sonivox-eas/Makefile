PORTNAME=	sonivox-eas
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Sonivox EAS for Qt
WWW=		https://github.com/pedrolcl/Linux-SonivoxEas

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdrumstick-alsa.so:audio/drumstick \
		libGLX.so:graphics/libglvnd \
		libpulse.so:audio/pulseaudio \
		libsonivox.so:audio/sonivox

USES=		cmake compiler:c++17-lang desktop-file-utils pkgconfig qt:6
USE_QT=		base
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	pedrolcl
GH_PROJECT=	Linux-SonivoxEas

CMAKE_ARGS=	-DUSE_QT=6

.include <bsd.port.mk>
