# $FreeBSD$

PORTNAME=	pulseaudio-qt
DISTVERSION=	1.2
MASTER_SITES=	KDE/stable/${PORTNAME}
CATEGORIES=	audio kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Pulseaudio bindings for Qt

LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libpulse.so:audio/pulseaudio

USES=		cmake compiler:c++11-lib cpe gettext kde:5 \
		pkgconfig qt:5 shebangfix tar:xz
USE_KDE=	coreaddons ecm doctools i18n
USE_QT=		core dbus gui \
		buildtools_build qmake_build

.include <bsd.port.mk>
