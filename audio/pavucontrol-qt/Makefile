# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	pavucontrol-qt
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	LXQT/${PORTNAME}

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	PulseAudio mixer in Qt

LICENSE=	GPLv2

LIB_DEPENDS=	libpulse.so:audio/pulseaudio

USES=	cmake compiler:c++11-lang gettext-runtime localbase:ldflags qt:5 \
	lxqt pkgconfig tar:xz gnome
USE_QT=	buildtools_build qmake_build core dbus gui linguisttools \
	widgets
USE_LXQT=	buildtools
USE_GNOME=	glib20

PLIST_FILES=	bin/pavucontrol-qt \
		share/applications/pavucontrol-qt.desktop

.include <bsd.port.mk>
