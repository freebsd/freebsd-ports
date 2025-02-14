PORTNAME=	pulseaudio-qt
DISTVERSION=	1.7.0
MASTER_SITES=	KDE/stable/${PORTNAME}
CATEGORIES=	audio kde
PKGNAMESUFFIX=	6

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Pulseaudio bindings for Qt
WWW=		https://invent.kde.org/libraries/pulseaudio-qt

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

LIB_DEPENDS=	libpulse.so:audio/pulseaudio

USES=		cmake compiler:c++20-lang gettext gl gnome kde:6 \
		pkgconfig qt:6 shebangfix tar:xz
USE_GL=		gl opengl # GLX
USE_GNOME=	glib20
USE_KDE=	ecm:build
USE_QT=		base

PLIST_SUB=	SOVERSION=${DISTVERSION}

.include <bsd.port.mk>
