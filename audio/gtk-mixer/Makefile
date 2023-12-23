PORTNAME=	gtk-mixer
DISTVERSION=	1.0.3
PORTREVISION=	2
CATEGORIES=	audio

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	GTK based volume control tool
WWW=		https://github.com/rozhuk-im/gtk-mixer

LICENSE=	GPLv2

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		cmake gnome pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	rozhuk-im
USE_GNOME=	cairo gdkpixbuf2 gtk30

DESKTOP_ENTRIES=	"GTK-Mixer" \
			"${COMMENT}" \
			"multimedia-volume-control" \
			"${PORTNAME}" \
			"GTK;AudioVideo;Audio;Mixer;" \
			true

PLIST_FILES=	bin/gtk-mixer

.include <bsd.port.mk>
