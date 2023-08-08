PORTNAME=	pulseaudio-qt
DISTVERSION=	1.3
MASTER_SITES=	KDE/stable/${PORTNAME}
PORTREVISION=	1
CATEGORIES=	audio kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Pulseaudio bindings for Qt
WWW=		https://github.com/KDE/pulseaudio-qt

LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libpulse.so:audio/pulseaudio

USES=		cmake compiler:c++11-lib gettext kde:5 \
		pkgconfig qt:5 shebangfix tar:xz
USE_KDE=	ecm:build
USE_QT=		core dbus gui \
		buildtools:build qmake:build

.include <bsd.port.mk>
