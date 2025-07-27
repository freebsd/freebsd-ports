PORTNAME=	pavucontrol-qt
PORTVERSION= 	2.2.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	LXQT/${PORTNAME}

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	PulseAudio mixer in Qt6
WWW=		https://github.com/lxqt/pavucontrol-qt/

LICENSE=	GPLv2

LIB_DEPENDS=	libpulse.so:audio/pulseaudio

USES=		cmake compiler:c++20-lang gettext-runtime localbase:ldflags \
		lxqt:2 qt:6 perl5 pkgconfig tar:xz gnome
USE_PERL5=	build
USE_QT=		base:run tools:build
USE_LXQT=	buildtools2
USE_GNOME=	glib20

.include <bsd.port.mk>
